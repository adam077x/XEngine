#include "Core/Application.h"

int main() {
	Application application = Application(800, 600, "XEngine");

	application.Run();

	return 0;
}
