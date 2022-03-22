Optional::is_none() трябва просто да проверява дали има резултат или няма, това което си направил е некоректно, но минава тестовете. 
В ElectionResultsDatabase::addResultsFromFile() може да използваш operator>> за ElectionResultsDatabase, който да използва operator>> за SectionVotes наготово.

Link to excersise
https://docs.google.com/document/d/11wIbxbJZ47fIBAVgGW_Zmm1YP5Up1IPJSTftABfhwqo/edit?usp=sharing