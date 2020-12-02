#include <stdio.h>
#include "myBank.h"
double matrix[2][50];

int
main ()
{
  double Amount = 0;
  int acountnum = 0;
  int x = 0;
  double y = 0.0;
  double n = 0.0;
  int in = 0;


  char ch = '1';

  while (ch != 'E')
    {
      printf ("\n");
      printf ("Please choose a transaction type:\n");
      printf ("O-Open Account\n");
      printf ("B-Balance Inquiry\n");
      printf ("D-Deposit\n");
      printf ("W-Withdrawal\n");
      printf ("C-Close Account\n");
      printf ("I-Interest\n");
      printf ("P-Print\n");
      printf ("E-Exit\n");
      scanf (" %c", &ch);


      switch (ch)
	{

	case 'O':
	  printf ("Please enter amount for deposit: ");
	  y = scanf ("%lf", &Amount);
	  if (y == 0)
	    {
	      printf ("Failed to read the amount\n");
	      break;

	    }

	  if (Amount < 0)
	    {
	      printf ("Invalid Amount\n");
	      break;
	    }

	  else if (y < 0)
	    {
	      printf ("Invalid Amount\n");
	      break;
	    }
	  OpenAnAccount(Amount);
	  break;



	case 'B':

	  printf ("Please enter account number: ");
	  x = scanf ("%d", &acountnum);

	  if (x == 0)
	    {
	      printf ("Failed to read the account number\n");
	      break;
	    }


	  if (acountnum > 951 || acountnum < 901)
	    {
	      printf ("Invalid account number\n");
	      break;
	    }

	  inquiry (acountnum);
	  break;




	case 'D':
	  printf ("Please enter account number: ");
	  x = scanf ("%d", &acountnum);
	  if (x == 0)
	    {
	      printf ("Failed to read the account number\n");
	      break;
	    }

	  if (acountnum > 950 || acountnum < 901)
	    {
	      printf ("Invalid account number\n");
	      break;
	    }

	  if (matrix[1][acountnum - 901] == 0)
	    {
	      printf ("This account is closed\n");
	      break;
	    }


	  printf ("Please enter the amount to deposit: ");

	  y = scanf ("%lf", &Amount);

	  if (y == 0)
	    {
	      printf ("Failed to read the amount\n");
	      break;
	    }
	  if (Amount < 0)
	    {
	      printf ("Cannot deposit a negative amount\n");
	      break;
	    }

	  Deposit (acountnum, Amount);
	  break;




	case 'W':
	  printf ("Please enter account number: ");

	  x = scanf ("%d", &acountnum);
	  if (x == 0)
	    {
	      printf ("Failed to read the account number\n");
	      break;
	    }

	  if (matrix[1][acountnum - 901] == 0)
	    {
	      printf ("This account is closed\n");
	      break;
	    }


	  if (acountnum > 951 || acountnum < 901)
	    {
	      printf ("Invalid account number\n");
	      break;
	    }



	  printf ("Please enter the amount to withdraw: ");
	  y = scanf ("%lf", &Amount);
	  if (y == 0)
	    {
	      printf ("Failed to read the account number\n");
	      break;
	    }

	  if (y == 0)
	    {
	      printf ("This account is closed\n");
	    }

	  if (y > 0)
	    {
	      withdraw (acountnum, Amount);
	    }
	  break;

	case 'C':
	  printf ("Please enter account number: ");

	  x = scanf ("%d", &acountnum);
	  if (x == 0)
	    {
	      printf ("Failed to read the account number\n");
	      break;
	    }
	  if (acountnum > 951 || acountnum < 901)
	    {
	      printf ("Invalid account number\n");
	      break;
	    }

	  if (matrix[1][acountnum - 901] == 0)
	    {
	      printf ("This account is already closed\n");
	      break;
	    }
	  if (x == 0)
	    {
	      printf ("This account is closed\n");
	      break;
	    }

	  AccountClosing (acountnum);

	  break;

	case 'I':
	  printf ("Please enter interest rate: ");

	  n = scanf ("%d", &in);
	  if (n == 0)
	    {
	      printf ("Failed to read the interest rate\n");
	      break;
	    }

	  if (in < 0)
	    {
	      printf ("Invalid interest rate\n");
	      break;
	    }



	  interest (matrix, in);

	  break;


	case 'P':
	  AllAccounts (matrix);


	  break;
	case 'E':
	  ClosingAndExit (matrix);

	  break;

	default:
	  printf ("Invalid transaction type\n");

	}
    }
  return 0;
}
