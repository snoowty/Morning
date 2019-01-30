void setup() {
  size(500, 500);
  
  colorMode(RGB, 256);
  smooth();
}
void draw() {
  int step = 10;
  background(255);
 
  float r = 0.9*width/2;
 
  noFill();
  stroke(24, 48, 151, 150);
  beginShape(LINES);
  int i, j;
  for ( i = 0, j = 0; i < 360*22; i=i+5, j=j+5*step ) {
    vertex(width/2 + r*cos(2*3.14*(i/360.0)), height/2 + r*sin(2*3.14*(i/360.0)));
    vertex(width/2 + r*cos(2*3.14*(j/360.0)), height/2 + r*sin(2*3.14*(j/360.0)));
  }
  endShape(CLOSE);
}
 
void keyPressed()
{
  save("output.png");
}