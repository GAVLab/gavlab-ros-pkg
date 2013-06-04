Header header
    uint32 seq
    time stamp
    string frame_id

string  gps_id
float64 gps_time
int8    health[32]

# Positioning
float64[32] semimajor_axis    # sqrt(A), SQUARE ROOT of semi major axis (meters)
float64[32] mean_anomaly      # M0, Mean anomoly of reference time (rad)
float64[32] eccentricity      # ecc, 
float64[32] perigee_arg       # omega, Arguement of perigee (rad)
float64[32] cos_latitude      # cuc, Arguement of latitude, amplitude of cosine (rad)
float64[32] sin_latitude      # cus, Arguement of latitude, amplitude of sine (rad)
float64[32] cos_orbit_radius  # crc, Orbit radius, amplitude of cosine (rad)
float64[32] sin_orbit_radius  # crs, Orbit radius, amplitude of sine (rad)
float64[32] cos_inclination   # cic, Inclination, amplitude of cosine (rad)
float64[32] sin_inclination   # cis, Inclination, amplitude of sine (rad)
float64[32] inclination_angle # I0, Inclination angle at reference time (rad)
float64[32] right_ascension   # omega0,  Right ascension (rad)

# Movement
float64[32] mean_motion_diff  # Delta N, Mean motion difference (rad/s)
float64[32] inclination_rate  # I dot, Rate of inclination angle (rad/s)
float64[32] ascension_rate    # omega0 dot, Rate of right ascension (rad/s)

# Timing
float64[32] time_of_week      # tow, Time stamp of subframe 0 (seconds)
float64[32] reference_time    # toe, Reference time for ephemeris (seconds)
float64[32] clock_correction  # toc, SV clock correction term (seconds)
float64[32] group_delay       # tgd, Estimated group delay difference (seconds)
float64[32] clock_aging_1     # af0, Clock aging parameter (seconds)
float64[32] clock_aging_2     # af1, Clock aging parameter (seconds/seconds)
float64[32] clock_aging_3     # af2, Clock aging parameter (seconds/seconds/seconds)