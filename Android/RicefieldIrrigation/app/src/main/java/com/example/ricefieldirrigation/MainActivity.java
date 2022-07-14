package com.example.ricefieldirrigation;

import static android.content.Context.MODE_PRIVATE;

import android.content.SharedPreferences;
//import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.ToggleButton;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {
    private TextView vmode, vwatersensor1, vwatersensor2, vstatusvalve1, vstatusvalve2;
    private Button bon1, boff1, bon2, boff2;
    private ToggleButton bmode;
    private ImageView vstatuscolor1, vstatuscolor2;

    private DatabaseReference database;

    private static String MY_PREFS = "switch_prefs";
    private static String SWITCH_STATUS = "switch_status";

    boolean switch_status;

    SharedPreferences myPreferences;
    SharedPreferences.Editor myEditor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        database = FirebaseDatabase.getInstance().getReference();
        FirebaseDatabase mdatabase = FirebaseDatabase.getInstance();

        vmode = (TextView) findViewById(R.id.statusmode);
        vwatersensor1 = (TextView) findViewById(R.id.valuesensor);
        vwatersensor2 = (TextView) findViewById(R.id.valuesensor2);
        vstatusvalve1 = (TextView) findViewById(R.id.statustext);
        vstatusvalve2 = (TextView) findViewById(R.id.statustext2);
        bon1 = (Button) findViewById(R.id.manualon);
        boff1 = (Button) findViewById(R.id.manualoff);
        bon2 = (Button) findViewById(R.id.manualon2);
        boff2 = (Button) findViewById(R.id.manualoff2);
        bmode = (ToggleButton) findViewById(R.id.togglebutton);
        vstatuscolor1 = (ImageView) findViewById(R.id.statuscolor);
        vstatuscolor2 = (ImageView) findViewById(R.id.statuscolor2);

        myPreferences = getSharedPreferences(MY_PREFS, MODE_PRIVATE);
        myEditor = getSharedPreferences(MY_PREFS, MODE_PRIVATE).edit();

        switch_status = myPreferences.getBoolean(SWITCH_STATUS, false);
        bmode.setChecked(switch_status);

        //MODE
        bmode.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (compoundButton.isChecked()){
                    database.child("mode").setValue("AUTO");

                    myEditor.putBoolean(SWITCH_STATUS, true);
                    myEditor.apply();
                    bmode.setChecked(true);
                }
                else{
                    database.child("mode").setValue("MANUAL");
                    myEditor.putBoolean(SWITCH_STATUS, false);
                    myEditor.apply();
                    bmode.setChecked(false);
                }
            }
        });
        mdatabase.getReference("mode").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                vmode.setText(snapshot.getValue(String.class));
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        //VALUE OF WATER SENSOR
        mdatabase.getReference("Sensor1").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Integer valuesensor1 = snapshot.getValue(Integer.class);
                vwatersensor1.setText(String.valueOf(valuesensor1));
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
        mdatabase.getReference("Sensor2").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Integer valuesensor2 = snapshot.getValue(Integer.class);
                vwatersensor2.setText(String.valueOf(valuesensor2));
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        //STATUS VALVE
        mdatabase.getReference("Kondisi1").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Integer statusvalue = snapshot.getValue(Integer.class);
                if (statusvalue == 1){
                    vstatusvalve1.setText("ON");
                    vstatuscolor1.setImageResource(R.drawable.circle_green);
                }
                else if (statusvalue == 0){
                    vstatusvalve1.setText("OFF");
                    vstatuscolor1.setImageResource(R.drawable.circle_red);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        mdatabase.getReference("Kondisi2").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Integer statusvalue2 = snapshot.getValue(Integer.class);
                if (statusvalue2 == 1){
                    vstatusvalve2.setText("ON");
                    vstatuscolor2.setImageResource(R.drawable.circle_green);
                }
                else if (statusvalue2 == 0){
                    vstatusvalve2.setText("OFF");
                    vstatuscolor1.setImageResource(R.drawable.circle_red);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        //BUTTON MANUAL
        //FOR VALVE 1
        bon1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                database.child("pump1").setValue("1");
            }
        });
        boff1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                database.child("pump1").setValue("0");
            }
        });
        //FOR VALVE 1
        bon2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                database.child("pump2").setValue("1");
            }
        });
        boff2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                database.child("pump2").setValue("0");
            }
        });

    }
}