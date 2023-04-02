print "Enter a string: ";

chomp(my $str = <>);

if ( $str eq reverse($str) ) {
     print "The string is a palindrome!\n";
}
else {
     print "The string is not a palindrome. \n";
}