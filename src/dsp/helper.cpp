#include "helper.hpp"
#include "engine.hpp"


/**
 * @brief Fast sin approximation
 * @param angle Angle
 * @return App. value
 */
float fastSin(float angle) {
    float sqr = angle * angle;
    float result = -2.39e-08f;
    result *= sqr;
    result += 2.7526e-06f;
    result *= sqr;
    result -= 1.98409e-04f;
    result *= sqr;
    result += 8.3333315e-03f;
    result *= sqr;
    result -= 1.666666664e-01f;
    result *= sqr;
    result += 1.0f;
    result *= angle;
    return result;
}


/**
 * @brief Fast sin approximation with input wrapping of -PI..PI
 * @param angle Angle
 * @return App. value
 */
float fastSinWrap(float angle) {
    return fastSin(wrapTWOPI(angle));
}


/**
 * @brief Clip signal at bottom by value
 * @param in Sample input
 * @param clip Clipping value
 * @return Clipped sample
 */
float clipl(float in, float clip) {
    if (in < clip) return clip;
    else return in;
}


/**
 * @brief Clip signal at top by value
 * @param in Sample input
 * @param clip Clipping value
 * @return Clipped sample
 */
float cliph(float in, float clip) {
    if (in > clip) return clip;
    else return in;
}


/**
 * @brief Wrap input number between -PI..PI
 * @param n Input number
 * @return Wrapped value
 */
float wrapTWOPI(float n) {
    float b = 1.f / TWOPI * n;
    return (b - lround(b)) * TWOPI;
}


/**
 * @brief Get PLL increment depending on frequency
 * @param frq Frequency
 * @return  PLL increment
 */
float getPhaseIncrement(float frq) {
    return TWOPI * frq / engineGetSampleRate();
}


/**
 * @brief
 * @param N
 * @param phase
 * @return
 */
float BLIT(float N, float phase) {
    float tmp = sin((clipl(N - 1, 0.f) + 0.5f) * phase) * 1.f / sin(0.5f * phase);
    return (tmp - 1.f) * 0.5f;
}