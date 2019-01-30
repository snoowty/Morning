size(500,500);    // 画面サイズ 500 x 500 px
background(0);    // 背景色：黒
rectMode(CENTER); // 描画モードは中心を基準にする 
noFill();         // 塗りつぶしなし
strokeWeight(2); // 線幅を10pxに
stroke(255);      // 線色を白に
ellipse(width/2,height/2,200,200);  // ウィンドウ中心位置に200x200[px]で四角を描画
beginShape(LINES);
for(int j = 0; j < 100; j=j+2){
for( int i = 0; i < 360; i=i+10){
  float x = width/2 + (100+j)  * cos(2*3.14*i/360.0);
  float y = width/2 + (100+j)  * sin(2*3.14*i/360.0);
  vertex(x,y);
}
}
endShape(CLOSE);