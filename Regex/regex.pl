use strict;
use warnings;

if ($ARGV[0] =~ m/^[a-zA-Z0-9]+$/)
{
   print "Legitimate username.........\n";
}
else
{
   print "Illegitimate username!!!!!!!!!!\n";
}

if ($ARGV[1] =~ m/^[a-zA-Z0-9@#\$%^&*]+$/)
{
   print "Legitimate password..........\n";
}
else
{
   print "Illegitimate password!!!!!!!!!!!!\n";
}

