echo -n "Enter the name of a country:\t"
read country

echo -n "The official language of $country is "

case $country in

  "India")
  echo "Hindi";;

  "Lithuania")
  echo "Lithuanian";;

  "Romania" | "Maldova")
  echo "Romanian";;

  "Italy" | "Switzerland")
  echo "Italian";;

  *)
  echo "Unknown";;

esac



