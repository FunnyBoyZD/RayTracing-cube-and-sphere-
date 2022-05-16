#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "VectorsAndFunctions.h"

void SetWindow(int Width, int Height); //function to set a console size

int main() {
	int width = 120 * 2;
	int height = 30 * 2;
	SetWindow(width, height);
	float aspect = (float)width / height; //the ratio of width and height
	float pixelAspect = 11.0f / 24.0f; //aspect ratio of pixels
	char gradient[] = " .:!/r(l1Z4H9W8$@";
	int gradientSize = std::size(gradient) - 2;

	wchar_t* screen = new wchar_t[width * height];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	for (int t = 0; t < 10000; t++) {
		Vector2 light = Normalize(Vector2(-0.5, 0.5, -1.0));
		Vector2 spherePos = Vector2(0, 3, 0);
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				Vector1 sphere = Vector1((float)i, (float)j) / Vector1((float)width, (float)height) * 2.0f - 1.0f;
				sphere._x *= aspect * pixelAspect;
				Vector2 camPosition = Vector2(-6, 0, 0);
				Vector2 beamDirection = Normalize(Vector2(2, sphere));
				camPosition = RotateY(camPosition, 0.25);
				beamDirection = RotateY(beamDirection, 0.25);
				camPosition = RotateZ(camPosition, t * 0.01);
				beamDirection = RotateZ(beamDirection, t * 0.01);
				float diff = 1;
				for (int k = 0; k < 5; k++) {
					float minIt = 99999;
					Vector1 intersection = Sphere(camPosition - spherePos, beamDirection, 1);
					Vector2 n = 0;
					float albedo = 1;
					if (intersection._x > 0) {
						Vector2 itPoint = camPosition - spherePos + beamDirection * intersection._x;
						minIt = intersection._x;
						n = Normalize(itPoint);
					}
					Vector2 boxN = 0;
					intersection = Cube(camPosition, beamDirection, 1, boxN);
					if (intersection._x > 0 && intersection._x < minIt) {
						minIt = intersection._x;
						n = boxN;
					}
					intersection = Plane(camPosition, beamDirection, Vector2(0, 0, -1), 1);
					if (intersection._x > 0 && intersection._x < minIt) {
						minIt = intersection._x;
						n = Vector2(0, 0, -1);
						albedo = 0.5f;
					}
					if (minIt < 99999) {
						diff *= (AngleOfRotation(n, light) * 0.5f + 0.5f) * albedo;
						camPosition = camPosition + beamDirection * (minIt - 0.01f);
						beamDirection = Reflect(beamDirection, n);
					}
					else break;
				}
				int color = (int)(diff * 20);
				color = (int)GradientNumCheck((float)color, 0, (float)gradientSize);
				char pixel = gradient[color];
				screen[i + j * width] = pixel;
			}
		}
		screen[width * height - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0, 0 }, &dwBytesWritten);
	}
	return 0;
}

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}