package fr.urca.urcadb;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

public abstract class DAOBase<T> {

	public static final String DATABASE_NAME = "Students.db";
	public static final int DATABASE_VERSION = 2;

	public static final String[] SQL_CREATE_TABLE_ARRAY = {
			StudentDAO.CREATE_TABLE };

	//protected SQLiteDatabase mDb = null;
	protected UrcaDBHelper mHelper = null;

	public DAOBase(Context context) {

		mHelper = new UrcaDBHelper(context, DATABASE_NAME, null, DATABASE_VERSION );
		if (mHelper != null) Log.i("daobase","creation ok");
		else Log.i("daobase","creation nok");
		
	}

	public SQLiteDatabase open() {
		SQLiteDatabase mDb = mHelper.getWritableDatabase();
		return mDb;
	}

	public SQLiteDatabase openReadable() {
		SQLiteDatabase mDb = mHelper.getReadableDatabase();
		return mDb;
	}

//	public void close() {
//		mDb.close();
//	}

//	public SQLiteDatabase getDB() {
//		return mDb;
//	}
	
	public abstract long ajouter(T obj);
	
	public abstract int supprimer(long id);
	
	public abstract int modifier(T obj);
	
	public abstract T selectionner(long id);
	

}
