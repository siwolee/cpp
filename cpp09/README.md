# Module-specific rules
- 스탠다드 라이브러리의 컨테이너를 사용하시오
- `이전에 사용한 컨테이너는 사용할 수 없으며, 여기서 사용한 컨테이너 역시 다른 exersize 에서 사용 불가.`
- 문제를 풀기 전 모든 문제를 살펴보는 것을 권장합니다.


# Exercise 00: Bitcoin Exchange
 > Turn-in directory : ex00/ 
 >
 > Files to turn in : Makefile, main.cpp, 
 > BitcoinExchange.{cpp, hpp}
 >
 > Forbidden functions : None

특정한 일자의 특정한 양의 비트코인을 출력하는 프로그램을 만드시오.

날짜에 따른 비트코인 가격을 보여주는 csv 데이터베이스를 사용하며, 문제에서 제공됩니다.

매개변수로 두번째 데이터베이스를 받아, 계산할 다른 가격/날짜를 보관합니다.

당신의 프로그램은 이 룰을 따릅니다:
- 프로그램 이름: btc
- 매개변수 : 무조건 하나의 파일 
- 해당 파일의 모든 줄은 다음 포맷을 따릅니다: `yyyy-mm-dd | 가격`
- 유효한 값은 반드시  0-1000 사의 float 혹은 양의 정수여야 합니다.

Here is an example of an input.txt file:
```sh
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
```

input 파일 안에 있는 값을 사용합니다.

당신의 프로그램은 반드시 STD 출력에 값을 출력해야 합니다 - 데이터베이스에 명시된 교환비율에 맞는 값이 곱해진 값을.


`  # DB에 해당 날짜가 존재하지 않을 경우 자동으로 가장 가까운, 이전 날짜를 참조합니다. (이후가 아닙니다) `

The following is an example of the program’s use.
```sh
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>
```



# Exercise 01: Reverse Polish Notation

> Turn-in directory : ex01/
> 
> Files to turn in : Makefile, main.cpp, RPN.{cpp, hpp}
> 
> Forbidden functions : None

프로그램에 포함되어야 하는 내용:
- The program name is RPN.
- 역 폴란드 계산법을 따르는 프로그램
- 인자로 들어가는 수는 무조건 10 아래지만, 실행결과는 이 규칙을 따르지 않음.
- 실행 후 바른 결과를 STD 출력
- 실행중 에러는 STD 출력
- **해당 연산자 처리 필요 `+ - / *`**
- 최소 하나의 컨테이너
- 괄호/ 10 이상 수 무시
  

```sh
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>
```


# Exercise 02: PmergeMe

> Turn-in directory : ex02/
> 
> Files to turn in : Makefile, main.cpp, PmergeMe.{cpp, hpp}
> 
> Forbidden functions : None
> 

다음과 같은 프로그램을 작성합니다 : 
- 프로그램 이름: PmergeMe.
- 당신의 프로그램은 반드시 <u>연속된 양의 정수</u>(시퀀스)를 사용할 수 있어야 합니다.
sequence.
- 당신의 프로그램은 정수 시퀀스를 정렬하기 위해 반드시 merge-insert sort 알고리즘, 즉 포드 존슨 알고리즘을 사용해야 합니다.
- 만약 실행도중 에러가 발생한다면 표준 출력에 표시됩니다.

최소 두 개의 다른 컨테이너를 사용해서 해당 프로그램을 검증해야 합니다.

최소 3000개 이상의 정수를 다룰 수 있어야 합니다.

각 컨테이너를 위해 알고리즘을 만드는 것이 강하게 권장되며, generic function(type)을 사용하는 것은 권장되지 않습니다. 

아래는 한 줄마다 출력되어야 하는 정보에 대한 안내입니다 :
- 1줄: 정렬되지 않은 시퀀스에 따라오는 특정 텍스트
- 2줄: 정렬된 시퀀스에 따라오는 특정 텍스트 
- 3줄: 계산에 걸린 시간 및 첫번째 컨테이너의 이름
- 4줄: 계산에 걸린 시간 및 두번째 컨테이너의 이름

The format for the display of the time used to carry out your sorting
is free but the precision chosen must allow to clearly see the
difference between the two containers used.
Here is an example of a standard use:
```sh
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
```


이 예에서는 시간 표시가 의도적으로 이상합니다.
물론 모든 작업을 수행하는 데 사용된 시간을 표시해야 합니다.
작업, 정렬 부분과 데이터 관리 부분 모두.