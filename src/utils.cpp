#include <iostream>
#include "logger.hpp"

void print_header() {
  logger::print("-------------------------------------------");
  logger::print("---------         v2.0          -----------");
  logger::print("-------------------------------------------");
  logger::print("Use 'edit' to edit values file");
  logger::print("Type a number to load the value of that row");
  logger::print("Use 'exit' to exit the program ");
}

void clear() {
  // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
  std::cout << "\x1B[2J\x1B[H";
}

#ifdef WINBUILD
#include "windows.h"
void clear() {
  COORD topLeft  = { 0, 0 };
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO screen;
  DWORD written;

  GetConsoleScreenBufferInfo(console, &screen);
  FillConsoleOutputCharacterA(
      console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );
  FillConsoleOutputAttribute(
      console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
      screen.dwSize.X * screen.dwSize.Y, topLeft, &written
  );
  SetConsoleCursorPosition(console, topLeft);
}
#endif