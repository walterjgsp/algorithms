+++
draft= false
title = "FAQ"
description = "Asked and answered"
+++

## How to run C++ code?

All the C++ code were done using the C++14 version. To compile use the following command:

```bash
g++ -std=c++14 <INPUT_FILE_NAME> -o <OUTPUT_FILE_NAME>
```

And to run the code:

```bash
./<OUTPUT_FILE_NAME>
```

## How to run Kotlin code?

To compile use the following command:

```bash
kotlinc <INPUT_FILE_NAME> -include-runtime -d <OUTPUT_FILE_NAME>.jar
```

And to run the code:

```bash
java -jar <OUTPUT_FILE_NAME>
```
