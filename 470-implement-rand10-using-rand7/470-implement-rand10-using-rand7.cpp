// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
       int r;

	for (;;) {
		r = (rand7() - 1) * 7 + rand7() - 1;
		if (r < 40)
			break;
		r = r * 7 + rand7() - 1;
		if (r < 340)
			break;
		r = r * 7 + rand7() - 1;
		if (r < 2400)
			break;
	}

	return r % 10 + 1;
    }
};