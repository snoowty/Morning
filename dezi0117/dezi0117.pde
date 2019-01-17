Button[] button = new Button[16];

//int play_pos = 0;

//class Metro
//{
//  Metro() {
//  }
//  void set(int _ms) {
//    ms = _ms;
//    ms_stamp = millis();
//  }
//
//  boolean update() {
//    if ( (millis() - ms_stamp) > ms) {
//      ms_stamp = millis();
//      return true;
//    }
//    return false;
//  }
//
//  int ms;
//  long ms_stamp;
//}
//
//Metro metro;


void setup()
{
  size(500, 500);
  for (int i = 0; i < 16; i++) {
    button[i] = new Button();
    button[i].setup(100+(i%4)*100, 100+(i/4)*100, 80, false);
  }
  //  metro = new Metro();
  //  metro.set(3000);
}

void draw()
{
  //  if ( metro.update() == true ) {
  //    play_pos++;
  //    if ( play_pos > 15 )play_pos = 0;
  // button[play_pos].setcolor(
  //    println(play_pos);
  //  }
  background(0);
  for (int i = 0; i < 16; i++) {
    button[i].update();
    button[i].draw();
  }
}

