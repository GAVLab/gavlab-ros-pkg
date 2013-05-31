Header header
    uint32 seq
    time stamp
    string frame_id

# string gps_id

float64[32] clockCorrection  # toc, SV clock correction term (seconds)
float64[32] groupDelay # tgd, Estimated group delay difference (seconds)
float64[32] referenceTime # toe, Reference time for ephemeris (seconds)

float64[32] semiMajorAxis # sqrt(A), SQUARE ROOT of semi major axis (meters)
float64[32] meanMotionDiff # Delta N, Mean motion difference (rad/s)
float64[32] meanAnomaly  # M0, Mean anomoly of reference time (rad)
float64[32] eccentricity # ecc, Eccentricity
float64[32] perigeeArg # omega, Arguement of perigee (rad)

float64[32] cosLatitude # cuc, Arguement of latitude, amplitude of cosine (rad)
float64[32] sinLatitude # cus, Arguement of latitude, amplitude of sine (rad)

float64[32] cosOrbitRadius # crc, Orbit radius, amplitude of cosine (rad)
float64[32] sinOrbitRadius # crs, Orbit radius, amplitude of sine (rad)

float64[32] cosInclination # cic, Inclination, amplitude of cosine (rad)
float64[32] sinInclination # cis, Inclination, amplitude of sine (rad)

float64[32] inclinationAngle # I0, Inclination angle at reference time (rad)
float64[32] inclinationRate # I dot, Rate of inclination angle (rad/s)

float64[32] rightAscension # omega0,  Right ascension (rad)
float64[32] ascensionRate  # omega0 dot, Rate of right ascension (rad/s)

float64[32] clockAging1 # af0, Clock aging parameter (seconds)
float64[32] clockAging2 # af1, Clock aging parameter (seconds/seconds)
float64[32] clockAging3 # af2, Clock aging parameter (seconds/seconds/seconds)
float64[32] timeOfWeek # tow, Time stamp of subframe 0 (seconds)

int8[32] health # Health status