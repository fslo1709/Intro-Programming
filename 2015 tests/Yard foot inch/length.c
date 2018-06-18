void init(int length[3]) {
    length[0] = length[1] = length[2] = 0;
}
void add(int length[3], int i) {
    int tmp = length[2] + i;
    length[2] = tmp%12;
    tmp /= 12;
    tmp = length[1] + tmp;
    length[1] = tmp%3;
    tmp /= 3;
    length[0] += tmp;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    int tmp = lengtha[2] + lengthb[2];
    lengthc[2] = tmp%12;
    tmp /= 12;
    tmp += lengtha[1] + lengthb[1];
    lengthc[1] = tmp%3;
    tmp /= 3;
    lengthc[0] = lengtha[0] + lengthb[0] + tmp;
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
	int tmp = lengtha[1];
	if (lengtha[2]<lengthb[2]) {
		tmp--;
		lengthc[2] = lengtha[2] + 12 - lengthb[2];
	}
	else
		lengthc[2] = lengtha[2] - lengthb[2];
	int tmp2 = lengtha[0];
	if (tmp<lengthb[1]) {
		tmp2--;
		lengthc[1] = tmp + 3 - lengthb[1];
	}
	else
		lengthc[1] = tmp - lengthb[1];
	lengthc[0] = tmp2 - lengthb[0];
}