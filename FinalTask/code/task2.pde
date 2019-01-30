import processing.video.*;
 
Movie mov;
void setup()
{
  size(720, 406);
  noStroke();
  mov = new Movie(this, "sample.mp4");
  mov.noLoop();
  mov.play();
}
void draw()
{
 
  noFill();
  if ( mov.available() == true ) {
    background(0);  
    mov.read();
    mov.loadPixels();
    for ( int i = 0; i < mov.height; i=i+5 ) {
      beginShape();
      for ( int j = 0; j < mov.width; j++ ) {
        color c1 = mov.get(j, i);
        stroke(red(c1), green(c1), blue(c1));
        strokeWeight(10);
        //point(j, i-(red(c1)+green(c1)+blue(c1))/35);
       // text("YUKI",j, i);
       float gray = (red(c1)+green(c1)+blue(c1))/3;
       vertex(j,i-gray/10.0);
      }
      endShape();
    }
  }
  saveFrame("frames/######.png");
}
