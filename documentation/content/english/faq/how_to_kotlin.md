+++
question = "How to run Kotlin code?"
date = 2019-02-17T19:30:50-03:00
weight = 30
draft = false
+++

To compile use the following command:

{{< highlight bash >}}
  kotlinc <INPUT_FILE_NAME> -include-runtime -d <OUTPUT_FILE_NAME>.jar
{{< /highlight >}}

And to run the code:

{{< highlight bash >}}
  java -jar <OUTPUT_FILE_NAME>
{{< /highlight >}}
