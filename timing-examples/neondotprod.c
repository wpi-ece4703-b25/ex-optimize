#include <arm_neon.h>

float dot_product_neon(const float *a, const float *b, int count) {
    float32x4_t sum_vec = vdupq_n_f32(0.0f);    // Initialize to zero
    int i;
    
    // Process 4 elements at a time
    for (i = 0; i <= count - 4; i += 4) {
        float32x4_t va = vld1q_f32(&a[i]);
        float32x4_t vb = vld1q_f32(&b[i]);
        
        // Multiply and accumulate
        sum_vec = vmlaq_f32(sum_vec, va, vb);
    }
    
    // Horizontal sum of vector elements
    float32x2_t sum_pair = vadd_f32(vget_low_f32(sum_vec), 
                                     vget_high_f32(sum_vec));
    float sum = vget_lane_f32(vpadd_f32(sum_pair, sum_pair), 0);
    
    // Handle remaining elements
    for (; i < count; i++) {
        sum += a[i] * b[i];
    }
    
    return sum;
}
