

#include "Plotter.h"
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main()
{
	const double tmax = 10.0;
	const double h = 0.01;

	const double Vg = 1.0;
	const double R1 = 1.0;
	const double R2 = 2.0;
	const double L1 = 1.0;
	const double C1 = 1.0;

	Matrix<double> A(2, 2);
	Matrix<double> B(2, 1);
	Matrix<double> C(2, 2);
	Matrix<double> D(2, 1);

	Vector<double> x(2);
	Vector<double> u(1);
	Vector<double> y(2);

	Plotter plotter("RLC Circuit");
	plotter.SetLabels("iL (A)", "vC (V)");

	A(0, 0) = -R1 / L1;
	A(0, 1) = -1 / L1;
	A(1, 0) = 1 / C1;
	A(1, 1) = -1 / (R2 * C1);

	B(0, 0) = 1 / L1;
	B(1, 0) = 0.0;

	C(0, 0) = 1.0;
	C(0, 1) = 0.0;
	C(1, 0) = 0.0;
	C(1, 1) = 1.0;

	D(0, 0) = 0.0;
	D(1, 0) = 0.0;

	u[0] = Vg;

	x[0] = 0.0;
	x[1] = 0.0;

	for (double t = 0.0; t < tmax; t += h)
	{
		y = C*x + D*u;

		plotter.AddRow(t, y[0], y[1]);

		x = x + A*x*h + B*u*h;
	}

	plotter.Plot();

	return 0;
}