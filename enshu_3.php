<?php
$a = '*';
$b = '_';
$n = 99;

for($i = 0; $i < $n; $i++) {
  for($cnt = 0; $cnt < $n; $cnt) {
    if($i % 2 == 0) {
      if($cnt < 99) {
        echo '*';
        $cnt++;
      }
      if($cnt < 99) {
        echo '_';
        $cnt++;
      }
    }else {
      if($cnt < 99) {
        echo '_';
        $cnt++;
      }
      if($cnt < 99) {
        echo '*';
        $cnt++;
      }
    }
  }
  echo '<br>';
}
?>
