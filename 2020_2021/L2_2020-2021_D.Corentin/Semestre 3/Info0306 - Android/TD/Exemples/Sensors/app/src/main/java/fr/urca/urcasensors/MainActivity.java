package fr.urca.urcasensors;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "Capteur";
    SensorManager mSensorManager = null;
    Sensor mAccelerometer = null;
    Sensor mGeomagnetic = null;
    Sensor mLight = null;

    TextView mTextviewDirection = null;
    TextView mTextviewWarning = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTextviewDirection = ((TextView) findViewById(R.id.textviewDirection));
        mTextviewWarning = ((TextView) findViewById(R.id.textviewWarning));

        // Récupération du manager
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);

        // Récupération de l'accéléromètre par défaut
        mAccelerometer = mSensorManager
                .getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        // Récupération du magnétomètre par défaut
        mGeomagnetic = mSensorManager
                .getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);

        // Récupération du photomètre par défaut
        mLight = mSensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
    }

    @Override
    protected void onResume() {
        super.onResume();

        // Vérification de la présence des capteurs avec demande de surveillance
        // pour chaque

        if (mAccelerometer != null) {
            // Demande de surveillance du capteur
            mSensorManager.registerListener(mSensorEventListener, mAccelerometer,
                    SensorManager.SENSOR_DELAY_UI);
        }

        if (mGeomagnetic != null) {
            mSensorManager.registerListener(mSensorEventListener, mGeomagnetic,
                    SensorManager.SENSOR_DELAY_UI);
        }

        if (mLight != null) {
            mSensorManager.registerListener(mSensorEventListener, mLight,
                    SensorManager.SENSOR_DELAY_NORMAL);
        }
    }

    @Override
    protected void onPause() {
        super.onPause();

        // ////////////////
        // 1. Si on souhaite arrêter que l'accéléromètre on utilisera...
        // ////////////////

        // Vérification de la présence de l'accéléromètre
        if (mAccelerometer != null) {
            // Un accéléromètre est disponible
            // Demande l'arrêt de la surveillance du capteur
            mSensorManager.unregisterListener(mSensorEventListener, mAccelerometer);
        }

        // ////////////////
        // 2.Si on souhaite tous arrêter on utilisera
        // ////////////////

        mSensorManager.unregisterListener(mSensorEventListener);
    }

    SensorEventListener mSensorEventListener = new SensorEventListener(){

        float[] mGravityValues = null;
        float[] mGeomagneticValues = null;

        @Override
        public void onSensorChanged(SensorEvent event) {

            // ////////
            // 1. UrcaRace : diminuer les gaz dès que l’on dépasse 6g dans les virages
            //gauches et droits
            // ////////

            if (event.sensor == mAccelerometer) {
                float g1 = 9.80665f;
                // float gMax = g1 * 6f;
                float gMax = g1 * 1.5f; // Pour les tests uniquement 1.5g car le
                // capteur
                // n'est pas assez puissant.
                float x = Math.abs(event.values[0]);

                if (x > gMax) {
                    reduireGaz();
                }
            }

            // ////////
            // 2. Attention aux virages : affichage du message à l’écran lorsque l'angle du virage
            //dépasse les 5°
            // ////////

            // Création des tableaux de float vide.
            float[] R = new float[9];
            float[] I = new float[9];

            // Récupération des valeurs du capteur de gravité
            if (event.sensor == mAccelerometer) {
                mGravityValues = event.values.clone();
            }

            // Récupération des valeurs du capteur de champs magnétique
            if (event.sensor == mGeomagnetic) {
                mGeomagneticValues = event.values.clone();
            }

            // Quand on a reçu des valeurs pour les deux capteurs
            if (mGravityValues != null && mGeomagneticValues != null) {

                float[] orientationValues = new float[3];

                boolean successRotation = SensorManager.getRotationMatrix(R, I,
                        mGravityValues, mGeomagneticValues);

                if (successRotation) {

                    SensorManager.getOrientation(R, orientationValues);

                    //afficher la direction sur l’écran du pilote:
                    mTextviewDirection.setText(getDirectionFromDegrees(Math
                            .round(Math.toDegrees(orientationValues[0]))));

                    float inclinaison = Math.abs(Math.round(Math
                            .toDegrees(orientationValues[2])));
                    if (inclinaison > 5) {
                        mTextviewWarning.setText("Moins vite dans les virages");
                        // Inclinaison max 90°
                        // alors Normalisation
                        // Rétroéclérage du volant en fonction de l'angle
                        luminosite(inclinaison / 90.f);
                    } else {
                        mTextviewWarning.setText("");
                    }
                }
            }

            // ////////
            // 3. Données des capteurs de luminosité
            // ////////
            if (event.sensor == mLight) {

                float lightMax = mLight.getMaximumRange();
                float light = event.values[0];

                Log.i(TAG, "Puissance necessaire : " + mLight.getPower() + "mA");
                Log.i(TAG, "Valeur maximum : " + lightMax);
                Log.i(TAG, "Fabriquant : " + mLight.getVendor());
                Log.i(TAG, "Version : " + mLight.getVersion());
                Log.i(TAG, "Valeur actuel : " + light);

            }

        }

        @Override
        public void onAccuracyChanged(Sensor sensor, int i) {
        }
    };


    private String getDirectionFromDegrees(float degrees) {
        if (degrees >= -22.5 && degrees < 22.5) {
            return "N";
        }
        if (degrees >= 22.5 && degrees < 67.5) {
            return "NE";
        }
        if (degrees >= 67.5 && degrees < 112.5) {
            return "E";
        }
        if (degrees >= 112.5 && degrees < 157.5) {
            return "SE";
        }
        if (degrees >= 157.5 || degrees < -157.5) {
            return "S";
        }
        if (degrees >= -157.5 && degrees < -112.5) {
            return "SW";
        }
        if (degrees >= -112.5 && degrees < -67.5) {
            return "W";
        }
        if (degrees >= -67.5 && degrees < -22.5) {
            return "NW";
        }

        return null;
    }


    // Un boolean pour éviter d'afficher plusieurs fois le Toast...
    private boolean reduireGazEnabled = true;

    private void reduireGaz() {

        if (reduireGazEnabled) {
            Toast.makeText(this, "Réduction des gaz", Toast.LENGTH_SHORT)
                    .show();
            reduireGazEnabled = false;
        }
    }

    private void luminosite(float lu) {
        WindowManager.LayoutParams lp = getWindow().getAttributes();
        lp.screenBrightness = lu;
        getWindow().setAttributes(lp);
    }
}