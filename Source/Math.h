#pragma once
namespace math
{

#define PI (3.14159265359)

	float DegreesToRadians(float Degrees)
	{
		return Degrees * PI / 180.0f;
	}

	float RadiansToDegrees(float Radians)
	{
		return Radians * 180.0f / PI;
	}

	float Factorial(int Value)
	{
		int Ret = 1;
		for (int i = Value; i > 0; i--)
			Ret = Ret * i;
		return Ret;
	}

	float Pow(float Value, int Pow)
	{
		float Ret = 1;
		for (int i = 0; i < Pow; i++)
			Ret = Ret * Value;
		return Ret;
	}

	float Sin(float AnglesDeg, float Accuracy)
	{
		float AnglesRad = DegreesToRadians(AnglesDeg);
		float i = AnglesRad; float Ret = 0;
		bool Minus = false;
		for (int j = 1; j <= Accuracy; j += 2)
		{
			if (!Minus)
				Ret += Pow(i, j) / Factorial(j);
			else
				Ret -= Pow(i, j) / Factorial(j);
			Minus = !Minus;
		}
		return Ret;
	}

	float Sin(float AnglesDeg) {
		return Sin(AnglesDeg, 16);//16
	}

	float Cos(float AnglesDeg, float Accuracy)
	{
		float AnglesRad = DegreesToRadians(AnglesDeg);
		float Rad = (float)(PI / 2.0f) - AnglesRad;
		float ang = RadiansToDegrees(Rad);
		return Sin(ang, Accuracy);
	}

	float Cos(float AnglesDeg) {
		return Cos(AnglesDeg, 16);//16
	}

	float Tan(float AnglesDeg, float Accuracy)
	{
		float sinus = Sin(AnglesDeg, Accuracy);
		float cosinus = Cos(AnglesDeg, Accuracy);
		return sinus / cosinus;
	}

	float Tan(float AnglesDeg) {
		return Tan(AnglesDeg, 19);//19
	}


	float abs(float value) {
		if (value < 0) {
			return value*-1;
		}
		else {
			return value;
		}
	}


	int ceil(float num) {
		int inum = (int)num;
		if (num == (float)inum) {
			return inum;
		}
		return inum + 1;
	}

	int round(float f) {
		int i = (int)f;
		float tiny = f - i;
		if (tiny < 0.5f) {
			return i;
		}
		else {
			return i + 1;
		}
	}

};
