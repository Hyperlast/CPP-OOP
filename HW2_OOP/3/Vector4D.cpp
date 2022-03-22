#include "Vector4D.hpp"

Vector4D::Vector4D()
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		this->Vec.push_back(0);
	}
}

Vector4D::Vector4D(double a, double b, double c, double d)
{
	this->Vec.push_back(a);
	this->Vec.push_back(b);
	this->Vec.push_back(c);
	this->Vec.push_back(d);
}

void Vector4D::printf()
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		std::cout << Vec[i] << " ";
	}
}

double& Vector4D::operator[](const int idx)
{
	return this->Vec[idx];
}

Vector4D Vector4D::operator+(const Vector4D& plus) const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
		temp[i] = (this->Vec[i] + plus.Vec[i]);
	}
	return temp;
}

Vector4D& Vector4D::operator+=(const Vector4D& PEQ)
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		this->Vec[i] += PEQ.Vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& minus) const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
		temp[i] = (this->Vec[i] - minus.Vec[i]);
	}
	return temp;
}

Vector4D& Vector4D::operator-=(const Vector4D& MEQ)
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		this->Vec[i] -= MEQ.Vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& Mult) const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
		temp[i] = (this->Vec[i] * Mult.Vec[i]);
	}
	return temp;
}

Vector4D Vector4D::operator*(const double& Scalar)const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
		temp[i] = (this->Vec[i] * Scalar);
	}
	return temp;

}

Vector4D& Vector4D::operator*=(const Vector4D& Mult)
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		this->Vec[i] *= Mult.Vec[i];
	}
	return *this;
}

Vector4D& Vector4D::operator*=(const double& Scalar)
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		this->Vec[i] *= Scalar;
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& Div) const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
			temp[i] = (this->Vec[i] / Div.Vec[i]);

	}
	return temp;
}

Vector4D& Vector4D::operator/=(const Vector4D& DEQ)
{
	
	for (unsigned int i = 0; i < 4; ++i)
	{
			this->Vec[i] /=DEQ.Vec[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D& Eq)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] != Eq.Vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D& NEq)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] != NEq.Vec[i])
		{
			return true;
		}
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& Large)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] > Large.Vec[i])
		{
			return false;
		}

		if (this->Vec[i] < Large.Vec[i])
		{
			return true;
		}
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D& LAE)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] > LAE.Vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator>(const Vector4D& Small)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] < Small.Vec[i])
		{
			return false;
		}

		if (this->Vec[i] > Small.Vec[i])
		{
			return true;
		}
	}
	return false;
}

bool Vector4D::operator>=(const Vector4D& SAE)const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] < SAE.Vec[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!() const
{
	for (unsigned int i = 0; i < 4; ++i)
	{
		if (this->Vec[i] != 0)
		{
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const
{
	Vector4D temp;
	for (unsigned int i = 0; i < 4; ++i)
	{
		temp[i] = -this->Vec[i];
	}
	return temp;
}
