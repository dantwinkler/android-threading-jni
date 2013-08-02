package com.sample.threading.activities;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.sample.threading.R;

public class MasterActivity extends Activity {

	public static String CLASSNAME = MasterActivity.class.getSimpleName();

	Button start;
	
	EditText results;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		setContentView(R.layout.master);
		
		start = (Button) findViewById(R.id.startThread);

		start.setOnClickListener( new View.OnClickListener() {
			public void onClick(View v) {
				startThread();
			}
		});
	}

	@Override
	protected void onPause() {
		super.onPause();
	}

	@Override
	protected void onResume() {
		super.onResume();
	}

	@Override
	protected void onStop() {
		super.onStop();
	}
	
	static
	{
		try {
			System.loadLibrary("threadingjnilib");
		} catch(UnsatisfiedLinkError ule) {
			System.out.println("Unable to load library!");
			System.out.println(ule.getMessage());
		}

	}
	
	public native void startThread();
}
