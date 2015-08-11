#include <iostream>
#include <fstream>

char memory[2048], *p = memory;
std::string code;

int run(int start = 0, bool ignore = false)
{
  for (int i = start; i < code.length(); ++i)
  {
    if (ignore && !(code[i] == '[' || code[i] == ']')) continue;
    
    switch (code[i])
    {
      case '<': --p;                     break; // Move pointer to the left
      case '>': ++p;                     break; // Move pointer to the right
      case '+': ++*p;                    break; // Add to the current address
      case '-': --*p;                    break; // Sub from the current address
      case '.': putchar(*p);             break; // Print the current address
      case ',': *p = getchar();          break; // Get user input
      case '[': i = run(i+1, !*p);       break; // Start a new loop
      case ']': return *p ? start-2 : i; break; // End the current loop
    }
  }
  
  return 0;
}

int main()
{
  std::ifstream stream { "mandelbrot.b" };
  stream >> code;
  
  run();
}
