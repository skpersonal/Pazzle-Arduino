const int mazeSize = 16;
int maze[mazeSize][mazeSize];
int playerVec[] = {1, 1};
int select = 0;
int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  select = random(1);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setMap() {
  for (int a = 0; a < mazeSize; a++) {
    for (int b = 0; b < mazeSize; b++) {
      maze[a][b] = getMap(select, a, b);
    }
  }
}

void showMap() { //マップを表示(現在シリアル)
  for (int a = 0; a < mazeSize; a++) {
    for (int b = 0; b < mazeSize; b++) {
      if (playerVec[0] == b && playerVec[1] == a) {
        Serial.print(3);
      } else {
        Serial.print(maze[a][b]);
      }
      if (b == mazeSize - 1) {
        Serial.println();
      }
    }
  }
  if (checkGoal()) {
    Serial.println("ゲーム終了");
    Serial.println("かかった手順の回数は" + String(num) + "回です");
    void(* resetFunc) (void) = 0; //ソフトウェアリセット
  }
  num++;
  Serial.print(">");
}

boolean checkGoal() { //終了判定
  return maze[playerVec[1]][playerVec[0]] == 2;
}

void moveRight() { //右に移動
  while (maze[playerVec[1]][playerVec[0] + 1] != 1) {
    playerVec[0]++;
    if (maze[playerVec[1]][playerVec[0]] == 2) {
      break;
    }
  }
  showMap();
}

void moveLeft() { //左に移動
  while (maze[playerVec[1]][playerVec[0] - 1] != 1) {
    playerVec[0]--;
    if (maze[playerVec[1]][playerVec[0]] == 2) {
      break;
    }
  }
  showMap();
}

void moveUp() { //上に移動
  while (maze[playerVec[1] - 1][playerVec[0]] != 1) {
    playerVec[1]--;
    if (maze[playerVec[1]][playerVec[0]] == 2) {
      break;
    }
  }
  showMap();
}

void moveDown() { //下に移動
  while (maze[playerVec[1] + 1][playerVec[0]] != 1) {
    playerVec[1]++;
    if (maze[playerVec[1]][playerVec[0]] == 2) {
      break;
    }
  }
  showMap();
}
