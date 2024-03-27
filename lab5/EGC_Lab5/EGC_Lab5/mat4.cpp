#include "mat4.h"

namespace egc{
    mat4& egc::mat4::operator=(const mat4& srcMatrix)
    {
        // equalize
        for (int i = 0; i < 16; i++) {
			matrixData[i] = srcMatrix.matrixData[i];
		}
        return *this;
    }

    mat4 egc::mat4::operator*(float scalarValue) const
    {
        mat4 result;
        for (int i = 0; i < 16; i++) {
            result.matrixData[i] = matrixData[i] * scalarValue;
        }
        return result;
    }

    mat4 egc::mat4::operator*(const mat4& srcMatrix) const
    {
        mat4 result;
        result.matrixData[0] = matrixData[0] * srcMatrix.matrixData[0] + matrixData[4] * srcMatrix.matrixData[1] + matrixData[8] * srcMatrix.matrixData[2] + matrixData[12] * srcMatrix.matrixData[3];
        result.matrixData[1] = matrixData[1] * srcMatrix.matrixData[0] + matrixData[5] * srcMatrix.matrixData[1] + matrixData[9] * srcMatrix.matrixData[2] + matrixData[13] * srcMatrix.matrixData[3];
        result.matrixData[2] = matrixData[2] * srcMatrix.matrixData[0] + matrixData[6] * srcMatrix.matrixData[1] + matrixData[10] * srcMatrix.matrixData[2] + matrixData[14] * srcMatrix.matrixData[3];
        result.matrixData[3] = matrixData[3] * srcMatrix.matrixData[0] + matrixData[7] * srcMatrix.matrixData[1] + matrixData[11] * srcMatrix.matrixData[2] + matrixData[15] * srcMatrix.matrixData[3];
        result.matrixData[4] = matrixData[0] * srcMatrix.matrixData[4] + matrixData[4] * srcMatrix.matrixData[5] + matrixData[8] * srcMatrix.matrixData[6] + matrixData[12] * srcMatrix.matrixData[7];
        result.matrixData[5] = matrixData[1] * srcMatrix.matrixData[4] + matrixData[5] * srcMatrix.matrixData[5] + matrixData[9] * srcMatrix.matrixData[6] + matrixData[13] * srcMatrix.matrixData[7];
        result.matrixData[6] = matrixData[2] * srcMatrix.matrixData[4] + matrixData[6] * srcMatrix.matrixData[5] + matrixData[10] * srcMatrix.matrixData[6] + matrixData[14] * srcMatrix.matrixData[7];
        result.matrixData[7] = matrixData[3] * srcMatrix.matrixData[4] + matrixData[7] * srcMatrix.matrixData[5] + matrixData[11] * srcMatrix.matrixData[6] + matrixData[15] * srcMatrix.matrixData[7];
        result.matrixData[8] = matrixData[0] * srcMatrix.matrixData[8] + matrixData[4] * srcMatrix.matrixData[9] + matrixData[8] * srcMatrix.matrixData[10] + matrixData[12] * srcMatrix.matrixData[11];
        result.matrixData[9] = matrixData[1] * srcMatrix.matrixData[8] + matrixData[5] * srcMatrix.matrixData[9] + matrixData[9] * srcMatrix.matrixData[10] + matrixData[13] * srcMatrix.matrixData[11];
        result.matrixData[10] = matrixData[2] * srcMatrix.matrixData[8] + matrixData[6] * srcMatrix.matrixData[9] + matrixData[10] * srcMatrix.matrixData[10] + matrixData[14] * srcMatrix.matrixData[11];
        result.matrixData[11] = matrixData[3] * srcMatrix.matrixData[8] + matrixData[7] * srcMatrix.matrixData[9] + matrixData[11] * srcMatrix.matrixData[10] + matrixData[15] * srcMatrix.matrixData[11];
        result.matrixData[12] = matrixData[0] * srcMatrix.matrixData[12] + matrixData[4] * srcMatrix.matrixData[13] + matrixData[8] * srcMatrix.matrixData[14] + matrixData[12] * srcMatrix.matrixData[15];
        result.matrixData[13] = matrixData[1] * srcMatrix.matrixData[12] + matrixData[5] * srcMatrix.matrixData[13] + matrixData[9] * srcMatrix.matrixData[14] + matrixData[13] * srcMatrix.matrixData[15];
        result.matrixData[14] = matrixData[2] * srcMatrix.matrixData[12] + matrixData[6] * srcMatrix.matrixData[13] + matrixData[10] * srcMatrix.matrixData[14] + matrixData[14] * srcMatrix.matrixData[15];
        result.matrixData[15] = matrixData[3] * srcMatrix.matrixData[12] + matrixData[7] * srcMatrix.matrixData[13] + matrixData[11] * srcMatrix.matrixData[14] + matrixData[15] * srcMatrix.matrixData[15];
        return result;
    }

    vec4 egc::mat4::operator*(const vec4& srcVector) const
    {
        vec4 result;
        result.x = matrixData[0] * srcVector.x + matrixData[4] * srcVector.y + matrixData[8] * srcVector.z + matrixData[12] * srcVector.w;
        result.y = matrixData[1] * srcVector.x + matrixData[5] * srcVector.y + matrixData[9] * srcVector.z + matrixData[13] * srcVector.w;
        result.z = matrixData[2] * srcVector.x + matrixData[6] * srcVector.y + matrixData[10] * srcVector.z + matrixData[14] * srcVector.w;
        result.w = matrixData[3] * srcVector.x + matrixData[7] * srcVector.y + matrixData[11] * srcVector.z + matrixData[15] * srcVector.w;

        return result;
    }

    mat4 egc::mat4::operator+(const mat4& srcMatrix) const
    {
        mat4 result;
        for (int i = 0; i < 16; i++) {
			result.matrixData[i] = matrixData[i] + srcMatrix.matrixData[i];
		}
        return result;
    }

    float& egc::mat4::at(int i, int j)
    {
        return matrixData[i * 4 + j];
    }

    const float& egc::mat4::at(int i, int j) const
    {
        return matrixData[i * 4 + j];
    }

    float egc::mat4::determinant() const
    {
        float det = 0.0f;
        det += matrixData[0] * (matrixData[5] * (matrixData[10] * matrixData[15] - matrixData[11] * matrixData[14]) - matrixData[6] * (matrixData[9] * matrixData[15] - matrixData[11] * matrixData[13]) + matrixData[7] * (matrixData[9] * matrixData[14] - matrixData[10] * matrixData[13]));
        det -= matrixData[1] * (matrixData[4] * (matrixData[10] * matrixData[15] - matrixData[11] * matrixData[14]) - matrixData[6] * (matrixData[8] * matrixData[15] - matrixData[11] * matrixData[12]) + matrixData[7] * (matrixData[8] * matrixData[14] - matrixData[10] * matrixData[12]));
        det += matrixData[2] * (matrixData[4] * (matrixData[9] * matrixData[15] - matrixData[11] * matrixData[13]) - matrixData[5] * (matrixData[8] * matrixData[15] - matrixData[11] * matrixData[12]) + matrixData[7] * (matrixData[8] * matrixData[13] - matrixData[9] * matrixData[12]));
        det -= matrixData[3] * (matrixData[4] * (matrixData[9] * matrixData[14] - matrixData[10] * matrixData[13]) - matrixData[5] * (matrixData[8] * matrixData[14] - matrixData[10] * matrixData[12]) + matrixData[6] * (matrixData[8] * matrixData[13] - matrixData[9] * matrixData[12]));
        return det;
    }

     float egc::mat4::minor(int row, int col) const {
        // Create a temporary 3x3 matrix to compute the minor
        float temp[9];
        int index = 0;
        for (int i = 0; i < 4; ++i) {
            if (i == row) continue;
            for (int j = 0; j < 4; ++j) {
                if (j == col) continue;
                temp[index++] = matrixData[i * 4 + j];
            }
        }
        // Compute the determinant of the 3x3 submatrix
        return temp[0] * (temp[4] * temp[8] - temp[5] * temp[7]) -
            temp[1] * (temp[3] * temp[8] - temp[5] * temp[6]) +
            temp[2] * (temp[3] * temp[7] - temp[4] * temp[6]);
    }

    // Function to compute the cofactor of an element in the matrix
    float egc::mat4::cofactor(int row, int col) const {
        float minorValue = minor(row, col);
        // Apply the sign factor (-1)^(row + col)
        return (row + col) % 2 == 0 ? minorValue : -minorValue;
    }

    mat4 egc::mat4::inverse() const {
        mat4 result;
        float det = determinant();
        const float tolerance = 1e-6; // Define a tolerance value for near-zero determinants

        // Check if the determinant is close to zero
        if (fabs(det) < tolerance) {
            // Matrix is not invertible
            return result;
        }

        // Compute the inverse matrix
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                // Compute cofactor and divide by determinant
                result.matrixData[i * 4 + j] = cofactor(j, i) / det;
            }
        }
        return result;
    }

       

    mat4 egc::mat4::transpose() const
    {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
				result.matrixData[i * 4 + j] = matrixData[j * 4 + i];
			}
		}
        return result;
    }
}
