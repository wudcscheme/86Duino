/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
/*
 * vector3.cpp
 * Copyright (C) Andrew Tridgell 2012
 *
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AP_Math_freeimu.h"

template <typename T>
double Vector2<T>::length(void) const
{
	return pythagorous2(x, y);
}


// dot product
template <typename T>
T Vector2<T>::operator *(const Vector2<T> &v) const
{
    return x*v.x + y*v.y;
}

// cross product
template <typename T>
T Vector2<T>::operator %(const Vector2<T> &v) const
{
    return x*v.y - y*v.x;
}

template <typename T>
Vector2<T> &Vector2<T>::operator *=(const T num)
{
    x*=num; y*=num;
    return *this;
}

template <typename T>
Vector2<T> &Vector2<T>::operator /=(const T num)
{
    x /= num; y /= num;
    return *this;
}

template <typename T>
Vector2<T> &Vector2<T>::operator -=(const Vector2<T> &v)
{
    x -= v.x; y -= v.y;
    return *this;
}

template <typename T>
bool Vector2<T>::is_nan(void) const
{
    return isnan(x) || isnan(y);
}

template <typename T>
bool Vector2<T>::is_inf(void) const
{
    return isinf(x) || isinf(y);
}

template <typename T>
Vector2<T> &Vector2<T>::operator +=(const Vector2<T> &v)
{
    x+=v.x; y+=v.y;
    return *this;
}

template <typename T>
Vector2<T> Vector2<T>::operator /(const T num) const
{
    return Vector2<T>(x/num, y/num);
}

template <typename T>
Vector2<T> Vector2<T>::operator *(const T num) const
{
    return Vector2<T>(x*num, y*num);
}

template <typename T>
Vector2<T> Vector2<T>::operator -(const Vector2<T> &v) const
{
    return Vector2<T>(x-v.x, y-v.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator +(const Vector2<T> &v) const
{
    return Vector2<T>(x+v.x, y+v.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator -(void) const
{
    return Vector2<T>(-x,-y);
}

template <typename T>
bool Vector2<T>::operator ==(const Vector2<T> &v) const
{
    return (x==v.x && y==v.y);
}

template <typename T>
bool Vector2<T>::operator !=(const Vector2<T> &v) const
{
    return (x!=v.x && y!=v.y);
}

template <typename T>
double Vector2<T>::angle(const Vector2<T> &v2) const
{
    return acosf(((*this)*v2) / (this->length()*v2.length()));
}

// only define for double
template double Vector2<double>::length(void) const;
template double Vector2<double>::operator *(const Vector2<double> &v) const;
template double Vector2<double>::operator %(const Vector2<double> &v) const;
template Vector2<double> &Vector2<double>::operator *=(const double num);
template Vector2<double> &Vector2<double>::operator /=(const double num);
template Vector2<double> &Vector2<double>::operator -=(const Vector2<double> &v);
template Vector2<double> &Vector2<double>::operator +=(const Vector2<double> &v);
template Vector2<double> Vector2<double>::operator /(const double num) const;
template Vector2<double> Vector2<double>::operator *(const double num) const;
template Vector2<double> Vector2<double>::operator +(const Vector2<double> &v) const;
template Vector2<double> Vector2<double>::operator -(const Vector2<double> &v) const;
template Vector2<double> Vector2<double>::operator -(void) const;
template bool Vector2<double>::operator ==(const Vector2<double> &v) const;
template bool Vector2<double>::operator !=(const Vector2<double> &v) const;
template bool Vector2<double>::is_nan(void) const;
template bool Vector2<double>::is_inf(void) const;
template double Vector2<double>::angle(const Vector2<double> &v) const;
