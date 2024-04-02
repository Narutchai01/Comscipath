import React from "react";

// Abstract Notification Class
abstract class Notification {
  abstract send(message: string): string;
}

// Concrete Products
class EmailNotification extends Notification {
  send(message: string): string {
    return `Email sent with message: ${message}`;
  }
}

class SMSNotification extends Notification {
  send(message: string): string {
    return `SMS sent with message: ${message}`;
  }
}

class PushNotification extends Notification {
  send(message: string): string {
    return `Push Notification sent with message: ${message}`;
  }
}

type NotificationType = "email" | "sms" | "push";

class NotificationFactory {
  createNotification(type: NotificationType): Notification {
    switch (type) {
      case "email":
        return new EmailNotification();
      case "sms":
        return new SMSNotification();
      case "push":
        return new PushNotification();
      default:
        throw new Error("Notification type not supported");
    }
  }
}

function App() {
  const factory = new NotificationFactory();

  const email = factory.createNotification("email");

  const handleSendNotification = (e: React.MouseEvent<HTMLButtonElement>) => {
    const { name } = e.target as HTMLButtonElement;
    if (name === "email") {
      alert(email.send("Email Notification"));
    } else if (name === "sms") {
      alert(email.send("SMS Notification"));
    } else if (name === "push") {
      alert(email.send("Push Notification"));
    }
  };

  return (
    <>
      <button name="email" onClick={handleSendNotification}>
        email
      </button>
      <button name="sms" onClick={handleSendNotification}>
        sms
      </button>
      <button name="push" onClick={handleSendNotification}>
        Push
      </button>
    </>
  );
}

export default App;
