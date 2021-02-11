package fr.urca.urcapreferences;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Toast;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {

        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {

            Intent intent = new Intent(this, SettingsActivity.class);
            startActivity(intent);

            return false;
        }
        return super.onOptionsItemSelected(item);
    }

    static final String FILENAME = "urca.txt";

    public void writeClicked(View v) {

        String urca = "URCA - ";

        try {
            FileOutputStream fos = openFileOutput(FILENAME, Context.MODE_APPEND);
            fos.write(urca.getBytes());
            fos.close();

            Toast.makeText(this, "Enregistré", Toast.LENGTH_SHORT).show();
        } catch (IOException e) {
            Toast.makeText(this, "Une erreur s'est produite",
                    Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
    }

    public void readClicked(View v) {

        File fichier = new File(getFilesDir() + "/" + FILENAME);

        FileInputStream fis = null;

        try {
            fis = openFileInput(FILENAME);
            if (fis != null) {

                byte fileContent[] = new byte[(int) fichier.length()];

                fis.read(fileContent);
                String content = new String(fileContent);
                Toast.makeText(this, content, Toast.LENGTH_SHORT).show();

            }
        } catch (FileNotFoundException e) {
            Toast.makeText(this, "Fichier introuvable", Toast.LENGTH_SHORT)
                    .show();
            // e.printStackTrace();
        } catch (IOException e) {
            Toast.makeText(this, "Impossible de lire le fichier",
                    Toast.LENGTH_SHORT).show();
            // e.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    fis.close();
                }
            } catch (IOException e) {
                // e.printStackTrace();
            }
        }

    }

    public void deleteClicked(View v) {

        if (deleteFile(FILENAME)) {
            Toast.makeText(this, "Fichier supprimé", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Impossible de supprimer le fichier",
                    Toast.LENGTH_SHORT).show();
        }
    }

    // EXTERNAL STORAGE

    public boolean isExternalStorageWritable() {
        String state = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(state)) {
            return true;
        }
        return false;
    }

    public boolean isExternalStorageReadable() {
        String state = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(state)
                || Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
            return true;
        }
        return false;
    }

    private void showExternalStorage(boolean available) {

        if (available)
            Toast.makeText(this, "Stockage externe disponible",
                    Toast.LENGTH_SHORT).show();
        else
            Toast.makeText(this, "Stockage externe indisponible",
                    Toast.LENGTH_SHORT).show();
    }

    public void checkExternalRead(View v) {
        showExternalStorage(isExternalStorageReadable());
    }

    public void checkExternalWrite(View v) {
        showExternalStorage(isExternalStorageWritable());
    }

}