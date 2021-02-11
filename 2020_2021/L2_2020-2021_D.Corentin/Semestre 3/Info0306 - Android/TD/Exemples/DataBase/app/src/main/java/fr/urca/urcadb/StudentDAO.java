package fr.urca.urcadb;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.provider.BaseColumns;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;


public class StudentDAO extends DAOBase<Student> implements BaseColumns {

    public static final String TABLE_NAME = "student";
    public static final String KEY_NAME = "student_name";
    public static final String KEY_FIRSTNAME = "student_firstname";

    public static final String DEFAULT_SORT_ORDER = _ID + " ASC";

    public static final String CREATE_TABLE = "CREATE TABLE " + TABLE_NAME
            + " (" + _ID + " INTEGER PRIMARY KEY," + KEY_NAME + " TEXT,"
            + KEY_FIRSTNAME + " TEXT" + ");";

    public static final String DELETE_TABLE = "DROP TABLE IF EXISTS "
            + TABLE_NAME;

    public static final String[] KEY_ARRAY = { KEY_NAME, KEY_FIRSTNAME };

    public StudentDAO(Context context) {
        super(context);
    }

    @Override
    public long ajouter(Student obj) {

        ContentValues values = new ContentValues();
        values.put(KEY_NAME, obj.getNom());
        values.put(KEY_FIRSTNAME, obj.getPrenom());

        SQLiteDatabase db = open();
        long val = db.insert(TABLE_NAME, KEY_NAME, values);
        db.close();

        return val;
    }

    @Override
    public int supprimer(long id) {
        return 0;
    }

    @Override
    public int modifier(Student obj) {
        // TODO Auto-generated method stub
        return 0;
    }

    @Override
    public Student selectionner(long id) {

        String query = "SELECT * FROM " + TABLE_NAME + " WHERE " + _ID + " = ?";
        SQLiteDatabase db = open();
        Cursor cursor = db.rawQuery(query, new String[] {Long.toString(id)});

        if (cursor != null)
            cursor.moveToFirst();

        Student s = new Student(cursor.getLong(0), cursor.getString(1), cursor.getString(2));

        cursor.close();
        db.close();

        return s;
    }

    public int getStudentsCount() {

        String countQuery = "SELECT  * FROM " + TABLE_NAME;
        SQLiteDatabase db = openReadable();
        Cursor cursor = db.rawQuery(countQuery, null);
        int count = cursor.getCount();
        cursor.close();
        db.close();

        return count;
    }

    public void logcatAllStudents(){
        String query = "SELECT * FROM " + TABLE_NAME;
        SQLiteDatabase db = open();
        Cursor cursor = db.rawQuery(query,null);
        if (cursor != null)
            cursor.moveToFirst();

        while (!cursor.isAfterLast()) {
            Student s = new Student(cursor.getLong(0), cursor.getString(1), cursor.getString(2));
            Log.i("LogStudents", s.getNom() + " " + s.getPrenom());
            cursor.moveToNext();
        }

        cursor.close();
        db.close();
    }

    public List<String> AllStudents(){

        List<String> list = new ArrayList<String>();

        String query = "SELECT * FROM " + TABLE_NAME;
        SQLiteDatabase db = open();
        Cursor cursor = db.rawQuery(query,null);
        if (cursor != null)
            cursor.moveToFirst();

        while (!cursor.isAfterLast()) {
            Student s = new Student(cursor.getLong(0), cursor.getString(1), cursor.getString(2));
            Log.i(s.getNom(), s.getPrenom());

            list.add(s.getPrenom() + " " + s.getNom());

            cursor.moveToNext();
        }

        cursor.close();
        db.close();


        return list;
    }

    // private void test() {
    //
    // Cursor result = mDb.rawQuery("SELECT * FROM student", null);
    // result.moveToFirst();
    //
    // while (!result.isAfterLast()) {
    //
    // String nom = result.getString(1);
    // String prenom = result.getString(2);
    //
    // // Faire quelque chose avec les valeurs
    //
    // result.moveToNext();
    // }
    // result.close();
    // }

    // public long ajouter(Student s) {
    //
    // ContentValues values = new ContentValues();
    // values.put(KEY_NAME, s.getNom());
    // values.put(KEY_FIRSTNAME, s.getPrenom());
    //
    // return mDb.insert(TABLE_NAME, KEY_NAME, values);
    // }

    // public void supprimer(long id) {
    // mDb.delete(TABLE_NAME, _ID + " = ?", new String[] {String.valueOf(id)});
    // }

    // public void modifier(Student student) {

    // ContentValues value = new ContentValues();
    // value.put(KEY_FIRSTNAME, student.getPrenom());
    // mDb.update(TABLE_NAME, value, _ID + " = ?", new String[]
    // {String.valueOf(student.getId())});

    // }

    // public Student selectionner(long id) {
    //
    // String sql = "SELECT * FROM " + TABLE_NAME;
    // String[] selectionArgs = null;
    //
    // Cursor cursor = mDb.rawQuery(sql, selectionArgs);
    //
    // return null;
    // }

}
