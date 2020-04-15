int stCount(ST st) {
	return st->size;
}

int stEmpty(ST st) {
	if(stCount(st) == 0) {
		return 1;
	}
	return 0;
}
