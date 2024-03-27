#include "mat3.h"

namespace egc {

    mat3& egc::mat3::operator=(const mat3& srcMatrix)
    {
        // equalize
        for (int i = 0; i < 9; i++) {
			matrixData[i] = srcMatrix.matrixData[i];
		}
        return *this;
    }

    mat3 egc::mat3::operator*(float scalarValue) const
    {
        // multiply
        mat3 result;
        for (int i = 0; i < 9; i++) {
			result.matrixData[i] = matrixData[i] * scalarValue;
		}
        return result;
    }

    mat3 egc::mat3::operator*(const mat3& srcMatrix) const
    {
        // multiply
        mat3 result;
        result.matrixData[0] = matrixData[0] * srcMatrix.matrixData[0] + matrixData[3] * srcMatrix.matrixData[1] + matrixData[6] * srcMatrix.matrixData[2];
        result.matrixData[1] = matrixData[1] * srcMatrix.matrixData[0] + matrixData[4] * srcMatrix.matrixData[1] + matrixData[7] * srcMatrix.matrixData[2];
        result.matrixData[2] = matrixData[2] * srcMatrix.matrixData[0] + matrixData[5] * srcMatrix.matrixData[1] + matrixData[8] * srcMatrix.matrixData[2];
        result.matrixData[3] = matrixData[0] * srcMatrix.matrixData[3] + matrixData[3] * srcMatrix.matrixData[4] + matrixData[6] * srcMatrix.matrixData[5];
        result.matrixData[4] = matrixData[1] * srcMatrix.matrixData[3] + matrixData[4] * srcMatrix.matrixData[4] + matrixData[7] * srcMatrix.matrixData[5];
        result.matrixData[5] = matrixData[2] * srcMatrix.matrixData[3] + matrixData[5] * srcMatrix.matrixData[4] + matrixData[8] * srcMatrix.matrixData[5];
        result.matrixData[6] = matrixData[0] * srcMatrix.matrixData[6] + matrixData[3] * srcMatrix.matrixData[7] + matrixData[6] * srcMatrix.matrixData[8];
        result.matrixData[7] = matrixData[1] * srcMatrix.matrixData[6] + matrixData[4] * srcMatrix.matrixData[7] + matrixData[7] * srcMatrix.matrixData[8];
        result.matrixData[8] = matrixData[2] * srcMatrix.matrixData[6] + matrixData[5] * srcMatrix.matrixData[7] + matrixData[8] * srcMatrix.matrixData[8];
        return result;
    }

    vec3 egc::mat3::operator*(const vec3& srcVector) const
    {
        // multiply
        vec3 result;
        result.x = matrixData[0] * srcVector.x + matrixData[3] * srcVector.y + matrixData[6] * srcVector.z;
        result.y = matrixData[1] * srcVector.x + matrixData[4] * srcVector.y + matrixData[7] * srcVector.z;
        result.z = matrixData[2] * srcVector.x + matrixData[5] * srcVector.y + matrixData[8] * srcVector.z;
        return result;
    }

    mat3 egc::mat3::operator+(const mat3& srcMatrix) const
    {
        //add
        mat3 result;
        for (int i = 0; i < 9; i++) {
            result.matrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
        }
        return result;
    }

    float& egc::mat3::at(int i, int j)
    {
        return matrixData[i * 3 + j];
    }

    const float& egc::mat3::at(int i, int j) const
    {
        return matrixData[i * 3 + j];
    }

    float egc::mat3::determinant() const
    {
        float det = 0;
        det = matrixData[0] * (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]) - matrixData[1] * (matrixData[3] * matrixData[8] - matrixData[5] * matrixData[6]) + matrixData[2] * (matrixData[3] * matrixData[7] - matrixData[4] * matrixData[6]);
        return det;
    }

    mat3 egc::mat3::inverse() const
    {
        mat3 result;
        float det = determinant();
        if (det == 0) {
			return result;
		}
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
				result.matrixData[i * 3 + j] = (matrixData[(j + 1) % 3 * 3 + (i + 1) % 3] * matrixData[(j + 2) % 3 * 3 + (i + 2) % 3] - matrixData[(j + 1) % 3 * 3 + (i + 2) % 3] * matrixData[(j + 2) % 3 * 3 + (i + 1) % 3]) / det;
			}
		}
		return result;  
    }

    mat3 egc::mat3::transpose() const
    {
        mat3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.matrixData[i * 3 + j] = matrixData[j * 3 + i];
            }
        }
        return result;
    }

}