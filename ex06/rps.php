<?php
	$choice = readline("Choose rock, paper, or scissors: " );
	$compete = random_int(0, 2); // 0 - r, 1 - p, s - 2
	if ($choice != "rock" && $choice != "paper" && $choice != "scissors")
	{
		echo "Bad choice\n";
		return ;
	}
	// rock
	if ($choice == "rock")
	{
		if ($compete == 0)
		{
			echo "Tie, The computer chose rock.\n";
			return ;
		}
		if ($compete == 1)
		{
			echo "Sorry, you lost. The computer chose paper.\n";
			return ;
		}
		if ($compete == 2)
		{
			echo "Congratulations! You won! The computer chose scissors.\n";
			return ;
		}
	}

	// paper
	if ($choice == "paper")
	{
		if ($compete == 1)
		{
			echo "Tie, The computer chose paper.\n";
			return ;
		}
		if ($compete == 2)
		{
			echo "Sorry, you lost. The computer chose scissors.\n";
			return ;
		}
		if ($compete == 0)
		{
			echo "Congratulations! You won! The computer chose rock.\n";
			return ;
		}
	}
	
	// scissors
	if ($choice == "scissors")
	{
		if ($compete == 2)
		{
			echo "Tie, The computer chose scissors.\n";
			return ;
		}
		if ($compete == 0)
		{
			echo "Sorry, you lost. The computer chose rock.\n";
			return ;
		}
		if ($compete == 1)
		{
			echo "Congratulations! You won! The computer chose paper.\n";
			return ;
		}
	}
?>