#include <stdio.h>
extern double matrix[2][50];

int AcNum;

void
OpenAnAccount (double Amount)
{

  int i = 0;
  while (i < 50)
    {
      if (matrix[1][i] == 0)
	{
	  matrix[0][i] = Amount;
	  matrix[1][i] = i + 901;
	  break;
	}
      else
	i++;
    }
  printf ("New account number is: %d", i + 901);
  printf ("\n");
}


void
inquiry (int AcNum)
{
  if (matrix[1][AcNum - 901] != 0)
    {
      printf ("The balance of account number %.0lf ", matrix[1][AcNum - 901]);
      printf ("is: %.2lf", matrix[0][AcNum - 901]);
      printf ("\n");


    }
  else
    printf ("This account is closed\n");
}


void
Deposit (int AcNum, double Amount)
{

  if (matrix[1][AcNum - 901] != 0)
    {
      matrix[0][AcNum - 901] += Amount;
      printf ("The new balance is: %.2lf\n", matrix[0][AcNum-901]);

    }
  else
    printf ("This account is closed\n");

  if (Amount == 0)
    printf ("Cannot withdraw more than the balance\n");
}


void
withdraw (int AcNum, double Amount)
{

  if (matrix[1][AcNum - 901] != 0 && (matrix[0][AcNum - 901] - Amount) >= 0)
    {
      matrix[0][AcNum - 901] = (matrix[0][AcNum - 901]) - Amount;
      printf ("The new balance is: %.2lf", matrix[0][AcNum - 901]);
      printf ("\n");
    }
  else if (matrix[1][AcNum - 901] == 0)
    printf ("This bank account is closed\n");
  else if ((matrix[0][AcNum - 901] - Amount) < 0)
    {
      printf ("Cannot withdraw more than the balance\n");
    }

}

void
AccountClosing (int AcNum)
{
  if (matrix[1][AcNum - 901] != 0)
    {
      matrix[1][AcNum - 901] = 0;
      matrix[0][AcNum - 901] = 0;
    }
  printf ("Closed account number %d", AcNum);
  printf ("\n");

}

void
interest (double matrix[2][50], int in)
{

  int i = 0;
  while (i < 50)
    {
      if (matrix[1][i] != 0)
	{
	  matrix[0][i] += (matrix[0][i]) * in * 0.01;
	}
      i++;
    }
}

void
AllAccounts (double matrix[2][50])
{
  for (int i = 0; i < 50; i++)
    {
      if (matrix[1][i] != 0)
	{
	  printf ("The balance of account number %.0lf ", matrix[1][i]);
	  printf (" is: %.2lf", matrix[0][i]);
	  printf ("\n");
	}

    }
}



void
ClosingAndExit (double matrix[2][50])
{

  for (int i = 0; i < 50; i++)
    {
      matrix[1][i] = 0;
    }
}
