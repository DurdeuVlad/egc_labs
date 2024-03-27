#include "transform.h"
namespace egc{
    mat3 egc::translate(const vec2 translateArray)
    {
        mat3 result = mat3();
        result.matrixData[6] = translateArray.x;
        result.matrixData[7] = translateArray.y;
        return result;

    }

    mat3 egc::translate(float tx, float ty)
    {
        mat3 result = mat3();
        result.matrixData[6] = tx;
        result.matrixData[7] = ty;
        return result;
    }

    mat3 egc::scale(const vec2 scaleArray)
    {
        mat3 result = mat3();
        result.matrixData[0] = scaleArray.x;
        result.matrixData[4] = scaleArray.y;
        return result;
    }

    mat3 egc::scale(float sx, float sy)
    {
        mat3 result = mat3();
        result.matrixData[0] = sx;
        result.matrixData[4] = sy;
        return result;
    }

    mat3 egc::rotate(float angle)
    {
        mat3 result = mat3();
        for (int i = 0; i < 9; ++i) {
            result.matrixData[i] = 0.0f;
        }
        result.matrixData[0] = 1.0f;
        result.matrixData[4] = 1.0f;
        result.matrixData[8] = 1.0f;
        float radians = angle * PI / 180.0;
        result.matrixData[0] = cos(radians);
        result.matrixData[1] = sin(radians);
        result.matrixData[3] = -sin(radians);
        result.matrixData[4] = cos(radians);
        // Round very small values to zero
        for (int i = 0; i < 9; ++i) {
            if (fabs(result.matrixData[i]) < 1e-6) {
                result.matrixData[i] = 0.0f;
            }
        }
        return result;
    }

    mat4 egc::translate(const vec3 translateArray)
    {
        mat4 result = mat4();
        result.matrixData[12] = translateArray.x;
        result.matrixData[13] = translateArray.y;
        result.matrixData[14] = translateArray.z;
        return result;
    }

    mat4 egc::translate(float tx, float ty, float tz)
    {
        mat4 result = mat4();
        result.matrixData[12] = tx;
        result.matrixData[13] = ty;
        result.matrixData[14] = tz;
        return result;
    }

    mat4 egc::scale(const vec3 scaleArray)
    {
        mat4 result = mat4();
        // translate the matrix
        result.matrixData[0] = scaleArray.x;
        result.matrixData[5] = scaleArray.y;
        result.matrixData[10] = scaleArray.z;
        return result;
    }

    mat4 egc::scale(float sx, float sy, float sz)
    {
        mat4 result = mat4();
        result.matrixData[0] = sx;
        result.matrixData[5] = sy;
        result.matrixData[10] = sz;
        return result;
    }

    mat4 egc::rotateX(float angle)
    {
        mat4 result = mat4();
        for (int i = 0; i < 16; ++i) {
            result.matrixData[i] = 0.0f;
        }
        result.matrixData[0] = 1.0f;
        result.matrixData[5] = 1.0f;
        result.matrixData[10] = 1.0f;
        result.matrixData[15] = 1.0f;
        float radians = angle * PI / 180.0;
        result.matrixData[5] = cos(radians);
        result.matrixData[6] = sin(radians);
        result.matrixData[9] = -sin(radians);
        result.matrixData[10] = cos(radians);

        // Round very small values to zero
        for (int i = 0; i < 16; ++i) {
            if (fabs(result.matrixData[i]) < 1e-6) {
                result.matrixData[i] = 0.0f;
            }
        }
        return result;

    }

    mat4 egc::rotateY(float angle)
    {
        mat4 result = mat4();
        for (int i = 0; i < 16; ++i) {
            result.matrixData[i] = 0.0f;
        }
        result.matrixData[0] = 1.0f;
        result.matrixData[5] = 1.0f;
        result.matrixData[10] = 1.0f;
        result.matrixData[15] = 1.0f;
        float radians = angle * PI / 180.0;
        result.matrixData[0] = cos(radians);
        result.matrixData[2] = -sin(radians);
        result.matrixData[8] = sin(radians);
        result.matrixData[10] = cos(radians);

        // Round very small values to zero
        for (int i = 0; i < 16; ++i) {
            if (fabs(result.matrixData[i]) < 1e-6) {
                result.matrixData[i] = 0.0f;
            }
        }
        return result;
    }

    mat4 egc::rotateZ(float angle)
    {
        mat4 result = mat4();
        for (int i = 0; i < 16; ++i) {
            result.matrixData[i] = 0.0f;
        }
        result.matrixData[0] = 1.0f;
        result.matrixData[5] = 1.0f;
        result.matrixData[10] = 1.0f;
        result.matrixData[15] = 1.0f;
        float radians = angle * PI / 180.0;
        result.matrixData[0] = cos(radians);
        result.matrixData[1] = sin(radians);
        result.matrixData[4] = -sin(radians);
        result.matrixData[5] = cos(radians);

        // Round very small values to zero
        for (int i = 0; i < 16; ++i) {
            if (fabs(result.matrixData[i]) < 1e-6) {
                result.matrixData[i] = 0.0f;
            }
        }
        return result;
    }

}