
#include <cstdio>
#include <iostream>

using namespace std;
using namespace std::placeholders;


namespace ff42 {

class button {
 public:
  function<void(int)> onClick;
};

class player {
 public:
  void play(void* sender, int param) {
    printf("Play: %p => %d\n", (int*)sender, param);
    cout << "Play: " << sender << " => " << param << endl;
  }
  void stop(void* sender, int param) {
    printf("Stop: %p => %d\n", (int*)sender, param);
    cout << "Stop: " << sender << " => " << param << endl;
  }
};

button playButton, stopButton;
player thePlayer;

void connect() {
  // The first argument of member function is a pointer this.
  playButton.onClick = bind(&player::play, &thePlayer, &playButton, _1);
  stopButton.onClick = bind(&player::stop, &thePlayer, &stopButton, _1);
}

void test42_bind_and_function() {
  cout << "\ntest42_bind_and_function()........................\n";

  connect();
  playButton.onClick(0);
  stopButton.onClick(7);
}
}  // namespace ff42


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff42::test42_bind_and_function();

  return 0;
}


