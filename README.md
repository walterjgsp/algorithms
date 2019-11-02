[![Build Status](https://travis-ci.com/walterjgsp/algorithms.svg?branch=master)](https://travis-ci.com/walterjgsp/algorithms)
[![CodeFactor](https://www.codefactor.io/repository/github/walterjgsp/algorithms/badge)](https://www.codefactor.io/repository/github/walterjgsp/algorithms)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/798842654ab045da9080cd4148f64456)](https://www.codacy.com/app/walterjgsp/algorithms?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=walterjgsp/algorithms&amp;utm_campaign=Badge_Grade)

<div align="center">
    <h1 align="center">
    Project Algorithm 
    </h1>
  <img  width="50" height="50" src="./icon.svg">
</div>

Repository for algorithms, problems and data structures that we have used. This serves as a reference for everyone interested.
For any suggestion on algorithm, problem or data structure, just open an issue with question label.

This repo contains questions from LeetCode (most of them), HackerRank, CodeSignal and LintCode.
We suggest you to try their platform so you can get new problems and articles about algorithms.

The documentation for this project can be found at: <https://walterjgsp.github.io/algorithms/>

The problmes list can be found at [Problems](PROBLEMS.md)

## Run C++

All the C++ code were done using the C++14 version. To compile use the following command:

```bash
g++ -std=c++14 <INPUT_FILE_NAME> -o <OUTPUT_FILE_NAME>
```

And to run the code:

```bash
./<OUTPUT_FILE_NAME>
```

## Run Kotlin

First is necessary to install Kotlin command line [kotlinc](https://kotlinlang.org/docs/tutorials/command-line.html)

To compile use the following command:

```bash
kotlinc <INPUT_FILE_NAME> -include-runtime -d <OUTPUT_FILE_NAME>.jar
```

And to run the code:

```bash
java -jar <OUTPUT_FILE_NAME>
```

## Run Java

All the Java code were done using the JDK 11 version. To compile use the following command:

```bash
javac <INPUT_FILE_NAME>
```

And to run the code:

```bash
java Main
```

## Run Python

All Python code were done using Python 3.7 version. To run the code use the following command:

```bash
python3 <INPUT_FILE_NAME> 
```

### Services

Services that i decided to use in this repository so i could test a more professional way of working:

* [SonarQube](https://sonarcloud.io/dashboard?id=walterjgsp-github)
* [TravisCI](https://travis-ci.org/walterjgsp/algorithms)
* [CodeFactor](https://www.codefactor.io/repository/github/walterjgsp/algorithms)
* [Codacy](https://app.codacy.com/project/walterjgsp/algorithms/dashboard)


#### Important commands

Add 0 in front of each filename:
```bash
rename 's/\d+/sprintf("%04d", $&)/e' *.cpp
```