#ifndef __AP_AHRS_HIL_H__
#define __AP_AHRS_HIL_H__

class AP_AHRS_HIL : public AP_AHRS
{
public:
    // Constructors
    AP_AHRS_HIL(AP_InertialSensor *ins, GPS *&gps) : AP_AHRS(ins, gps) {}

    // Accessors
    Vector3f get_gyro(void) {
        return _omega;
    }

    Matrix3f get_dcm_matrix(void) {
        Matrix3f m;
        m.from_euler(roll, pitch, yaw);
        return m;
    }

    // Methods
    void update(void) {
        _ins->update();
    }
    
    void setHil(float roll, float pitch, float yaw,
                float rollRate, float pitchRate, float yawRate);

    // return the current estimate of the gyro drift
    Vector3f get_gyro_drift(void) {
        return Vector3f(0,0,0);
    }

    // reset the current attitude, used on new IMU calibration
    void reset(bool recover_eulers=false) {
    }

    float get_error_rp(void) {
        return 0;
    }
    float get_error_yaw(void) {
        return 0;
    }

private:
    Vector3f _omega;
};

#endif // __AP_AHRS_HIL_H__
