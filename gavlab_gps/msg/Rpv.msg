Header header
    uint32 seq
    time stamp
    string frame_id

string gps_id_from
string gps_id_to
int64 gps_time   # GPS Time of output (ms into week)
int8 status # Output status
            #  2 : High precision solution available
            #  1 : Low precision solution only (high precision is zero)
            #  0 : Insufficient observations
            # -1 : Time stamps of input data do not match
            # -2 : Already computed solution for time stamp on input data
            # -3 : No L1 range measurements on receiver 1
            # -4 : No L2 range measurements on receiver 1
            # -5 : No L1 range measurements on receiver 2
            # -6 : No L2 range measurements on receiver 2
float64 ratio

RpvData lp
RpvData hp
