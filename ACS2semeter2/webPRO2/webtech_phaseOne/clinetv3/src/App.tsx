// import React from "react";

// abstract class Notification {
//   abstract send(message: string): string;
// }

// class EmailNotification extends Notification {
//   send(message: string): string {
//     return `Email sent with message: ${message}`;
//   }
// }

// class SMSNotification extends Notification {
//   send(message: string): string {
//     return `SMS sent with message: ${message}`;
//   }
// }

// class PushNotification extends Notification {
//   send(message: string): string {
//     return `Push Notification sent with message: ${message}`;
//   }
// }

// type NotificationType = "email" | "sms" | "push";

// class NotificationFactory {
//   createNotification(type: NotificationType): Notification {
//     switch (type) {
//       case "email":
//         return new EmailNotification();
//       case "sms":
//         return new SMSNotification();
//       case "push":
//         return new PushNotification();
//       default:
//         throw new Error("Notification type not supported");
//     }
//   }
// }

// function App() {
//   const factory = new NotificationFactory();

//   const handleSendNotification = (e: React.MouseEvent<HTMLButtonElement>) => {
//     const { name } = e.target as HTMLButtonElement;
//     if (name === "email") {
//       const noti = factory.createNotification(`${name}`);
//       alert(noti.send("Email Notification"));
//     } else if (name === "sms") {
//       const noti = factory.createNotification(`${name}`);
//       alert(noti.send("Email Notification"));
//       alert(noti.send("SMS Notification"));
//     } else if (name === "push") {
//       const noti = factory.createNotification(`${name}`);
//       alert(noti.send("Email Notification"));
//       alert(noti.send("Push Notification"));
//     }
//   };

//   return (
//     <>
//       <button name="email" onClick={handleSendNotification}>
//         email
//       </button>
//       <button name="sms" onClick={handleSendNotification}>
//         sms
//       </button>
//       <button name="push" onClick={handleSendNotification}>
//         Push
//       </button>
//     </>
//   );
// }

// export default App;

import React from "react";

// Abstract Notification Class
abstract class Notification {
  abstract createNotification(): Notification;
  send(message: string): string {
    return `${this.constructor.name} sent with message: ${message}`;
  }
}

// Concrete Products
class EmailNotification extends Notification {
  createNotification(): Notification {
    return new EmailNotification();
  }
}

class SMSNotification extends Notification {
  createNotification(): Notification {
    return new SMSNotification();
  }
}

class PushNotification extends Notification {
  createNotification(): Notification {
    return new PushNotification();
  }
}

function App() {
  const emailNoti = new EmailNotification().createNotification();
  const smsNoti = new SMSNotification().createNotification();
  const pushNoti = new PushNotification().createNotification();

  const handleSendNotification = (e: React.MouseEvent<HTMLButtonElement>) => {
    const { name } = e.target as HTMLButtonElement;
    let noti: Notification;

    switch (name) {
      case "email":
        noti = emailNoti;
        break;
      case "sms":
        noti = smsNoti;
        break;
      case "push":
        noti = pushNoti;
        break;
      default:
        throw new Error("Notification type not supported");
    }

    alert(noti.send(`${name} Notification`));
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
