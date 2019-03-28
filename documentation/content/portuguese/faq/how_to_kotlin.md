+++
question = "Como rodar código em Kotlin?"
date = 2019-02-17T19:30:50-03:00
weight = 30
draft = false
+++

Para compilar código em Kotlin use o seguinte comando:

{{< highlight bash >}}
  kotlinc <INPUT_FILE_NAME> -include-runtime -d <OUTPUT_FILE_NAME>.jar
{{< /highlight >}}

E para executar o código:

{{< highlight bash >}}
  java -jar <OUTPUT_FILE_NAME>
{{< /highlight >}}
