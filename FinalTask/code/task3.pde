BvhParser parserA = new BvhParser();
PBvh bvh[] = new PBvh[3];
 
import ddf.minim.*;
import ddf.minim.ugens.*;
 
Minim       minim;
AudioOutput out;
Oscil       wave[] = new Oscil[3];
Oscil       wave2[] = new Oscil[3];
Oscil       wave3[] = new Oscil[3];
Oscil       wave4[] = new Oscil[3];
 
public void setup()
{
  size( 1280, 720, P3D );
  background( 255 );
  noStroke();
  stroke(0);
  fill(0);
  frameRate( 30 );
 
  bvh[0] = new PBvh( loadStrings( "aachan.bvh"), 1 );
  bvh[1] = new PBvh( loadStrings( "kashiyuka.bvh"), 2 );
  bvh[2] = new PBvh( loadStrings( "nocchi.bvh"), 3 );
 
 
  minim = new Minim(this);
  // use the getLineOut method of the Minim object to get an AudioOutput object
  out = minim.getLineOut();
 
  // create a sine wave Oscil, set to 440 Hz, at 0.5 amplitude
  for ( int i = 0; i < 3; i++ ) {
    wave[i] = new Oscil( 440, 0.2f, Waves.SINE );
    wave[i].patch( out );
  }
   // create a sine wave Oscil, set to 440 Hz, at 0.5 amplitude
  for ( int i = 0; i < 3; i++ ) {
    wave2[i] = new Oscil( 440, 0.2f, Waves.SINE );
    wave2[i].patch( out );
  }
    for ( int i = 0; i < 3; i++ ) {
    wave3[i] = new Oscil( 440, 0.2f, Waves.SINE );
    wave3[i].patch( out );
  }
    for ( int i = 0; i < 3; i++ ) {
    wave4[i] = new Oscil( 440, 0.2f, Waves.SINE );
    wave4[i].patch( out );
  }
 
  loop();
}
 
int pos = 0;
public void draw()
{
  background(100);
  //camera
  float _cos = cos(millis() / 5000.f);
  float _sin = sin(millis() / 5000.f);
  //camera(width/4.f + width/4.f * _cos +200, height/2.0f-100, 550 + 150 * _sin, width/2.0f, height/2.0f, -400, 0, 1, 0);
  pos=pos-10;
  camera(width/2, height/4, -400, 
    width/2, height/2, 0, 
    0, 1, 0);
 
  //ground 地面を描いている
  fill( color( 255 ));
  stroke(127);
  line(width/2.0f, height/2.0f, -30, width/2.0f, height/2.0f, 30);
  stroke(127);
  line(width/2.0f-30, height/2.0f, 0, width/2.0f + 30, height/2.0f, 0);
  stroke(255);
  pushMatrix();
  translate( width/2, height/2-10, 0);
  scale(-1, -1, -1);
 
  //model
  for ( int i = 0; i < 3; i++ ) {
    bvh[i].update( millis() );
    bvh[i].draw();
  } 
  popMatrix();
 
  // 各3人の左手y座標の値に応じて、発音しているsin波の周波数を変更する
  // bvh[0],bvh[1],bvh[2]にはそれぞれのメンバーの座標データが保存されている。
  for ( int i  = 0; i < 3; i++ ) { 
    wave[i].setFrequency( 10*bvh[i].pos_x[3]); // 単位は[Hz]
  }
  for ( int i  = 0; i < 3; i++ ) { 
    wave2[i].setFrequency( 10*bvh[i].pos_y[3]); // 単位は[Hz]
  }
  
  for ( int i  = 0; i < 3; i++ ) { 
    wave3[i].setFrequency( 10*bvh[i].pos_x[4]); // 単位は[Hz]
  }
  for ( int i  = 0; i < 3; i++ ) { 
    wave4[i].setFrequency( 10*bvh[i].pos_y[4]); // 単位は[Hz]
  } 
  
  saveFrame("frames/######.png");
}
