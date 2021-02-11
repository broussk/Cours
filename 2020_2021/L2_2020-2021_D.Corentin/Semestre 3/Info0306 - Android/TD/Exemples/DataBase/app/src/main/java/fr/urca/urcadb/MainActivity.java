package fr.urca.urcadb;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    static ArrayAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        StudentDAO students = new StudentDAO(getApplicationContext());

        List<String> list = students.AllStudents();
        Log.i("Spinner", list.toString());

        adapter = new ArrayAdapter(this, android.R.layout.simple_spinner_item, list);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        Spinner spinner = (Spinner) findViewById(R.id.spinner);
        spinner.setAdapter(adapter);

        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {

                Log.i("Spinner", "Item selectionnée = " + i + " et Texte = " + ((TextView) adapterView.getChildAt(0)).getText());
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });
    }

    public void addStudent(View view) {

        String nom = ((EditText) findViewById(R.id.EditTextName)).getText()
                .toString();
        String prenom = ((EditText) findViewById(R.id.editTextFirsname))
                .getText().toString();

        Student student = new Student(nom, prenom);
        StudentDAO dao = new StudentDAO(getApplicationContext());
        long val = dao.ajouter(student);
        Log.i("Add", String.valueOf(val));

        adapter.add(student.getPrenom() + " " + student.getNom());
    }

    public void showRandom(View view) {

        StudentDAO student = new StudentDAO(getApplicationContext());
        Random r = new Random();
        int random;
        int max = student.getStudentsCount();

        Log.i("BD", "Taille BD = " + max);

        if (max==0){
            Toast.makeText(this, "Base de donnée vide", Toast.LENGTH_SHORT).show();
            return;
        }
        else if (max==1){
            random = 1;
        } else{
            random = 1 + r.nextInt((max - 1)>0?(max - 1):0);
        }

        Log.i("BD", "Taille BD = " + max + ", random = " + random);

        Student s = student.selectionner(random);
        Toast.makeText(this, s.getNom() + " " + s.getPrenom(), Toast.LENGTH_SHORT).show();
    }

    public void listAll(View view) {
        new StudentDAO(getApplicationContext()).logcatAllStudents();
    }
}