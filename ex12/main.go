package main

import (
  "bytes"
  "fmt"
  "net/smtp"
  "text/template"
)

func main() {

  // Sender data.
  from := "42pongjng@gmail.com"
  password := "tlpgnbcyhcsjmbmj"

  // Receiver email address.
  to := []string{
    "lee1052william@gmail.com",
  }

  // smtp server configuration.
  smtpHost := "smtp.gmail.com"
  smtpPort := "587"

  // Authentication.
  auth := smtp.PlainAuth("", from, password, smtpHost)

  t, _ := template.ParseFiles("template.html")

  var body bytes.Buffer

  mimeHeaders := "MIME-version: 1.0;\nContent-Type: text/html; charset=\"UTF-8\";\n\n"
  body.Write([]byte(fmt.Sprintf("Subject: This is a test subject \n%s\n\n", mimeHeaders)))

  t.Execute(&body, struct {
    Name    string
    Message string
  }{
    Name:    "From SMTP",
    Message: "This is a generated message.",
  })

  // Sending email.
  err := smtp.SendMail(smtpHost+":"+smtpPort, auth, from, to, body.Bytes())
  if err != nil {
    fmt.Println(err)
    return
  }
  fmt.Println("Email Sent!")
}