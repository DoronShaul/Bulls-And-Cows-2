/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include <iostream>
using namespace std;

#include "play.hpp"
#include "calculate.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main()
{

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0") // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "4321"), "0,4") // 0 bull, 4 pgia
			;

		testcase.setname("Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)	// guesser wins in one turn.
			.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)  // guesser loses by running out of turns
			.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101) // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)   // chooser loses technically by choosing an illegal number (too long).
			;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i = 0; i < 100; ++i)
		{
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true); // smarty should always win in at most 100 turns!
		}

		//OUR TESTS
		ConstantChooser cc1{"12569"}, cc2{"2089"}, cc3{"129"};
		ConstantGuesser cg1{"12569"}, cg2{"1457"}, cg3{"1269"};
		RandomChooser rc;
		SmartGuesser sg;
		testcase.setname("our tests")

			//checking the calculateBullAndPgia function.
			.CHECK_OUTPUT(calculateBullAndPgia("67891", "1111"), "chooser's and guesser's length does not match.")
			.CHECK_OUTPUT(calculateBullAndPgia("1122", "12345"), "chooser's and guesser's length does not match.")
			.CHECK_OUTPUT(calculateBullAndPgia("1113", "3331"), "0,2")			 // 0 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1155", "3145"), "2,0")			 // 2 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("5432", "2345"), "0,4")			 // 0 bull, 4 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("3999", "3999"), "4,0")			 // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1437", "1734"), "2,2")			 // 2 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("11133", "33313"), "1,2")		 // 1 bull, 2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("198452345", "892562315"), "4,3") // 4 bull, 3 pgia

			//checking the play function.
			.CHECK_EQUAL(play(cc1, cg1, 4, 100), 0)   //chooser's length too long.
			.CHECK_EQUAL(play(cc1, cg1, 5, 100), 1)   //guesser wins in one turn.
			.CHECK_EQUAL(play(cc2, cg3, 4, 100), 101) //guesser lose.
			.CHECK_EQUAL(play(cc3, cg2, 3, 30), 31)  //guesser's length too long.
			.CHECK_EQUAL(play(rc, sg, 4, 30)<=30, true)	 //smart guesser wins in under than 30 round.
			.CHECK_EQUAL(play(rc, sg, 4, 60)<=60,true)	 //smart guesser wins in under than 60 round.
			.CHECK_EQUAL(play(rc, sg, 4, 80)<=80,true)	 //smart guesser wins in under than 80 round.
			.CHECK_EQUAL(play(rc, sg, 4, 100)<=100,true)   //smart guesser wins in under than 100 rounds.
			.CHECK_EQUAL(play(rc, cg3, 4, 100), 101)  //const guesser loses.
			.CHECK_EQUAL(play(rc, cg2, 7, 100), 101)  //guesser's length too long.
			;

		grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	
	return 0;
}
