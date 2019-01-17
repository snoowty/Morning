class Button {
  Button()
  {
  }

  void setup(int _x, int _y, int _size, boolean _status) {
    x = _x;
    y = _y;
    size = _size;
    status = _status;
    previous_mousePressed = false;
    c = color(50, 50, 50);
  }

  void update()
  {
    if (sqrt( pow(x-mouseX, 2) + pow(y-mouseY, 2) ) < size/2 ) {
      println("in");
      if ( mousePressed = true && previous_mousePressed == false ) {
        status = !status;
      }
    } else {
      println("out");
    }

    if (status == true) {
      c = color(200, 200, 200);
    } else {
      c = color(50, 50, 50);
    }

    previous_mousePressed = mousePressed;
  }

  void draw() {
    noStroke();
    if (status) fill(200);
    fill(255);
    ellipse(x, y, size, size);
  }

  //  void setColor(int _color) {
  //    c = color(_color);
  //  }

  int x;
  int y;
  int size;
  boolean status;
  boolean previous_mousePressed;
  color c;
}

