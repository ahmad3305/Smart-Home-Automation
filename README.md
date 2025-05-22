# Smart-Home-Automation

This is a project for managing smart homes and devices. It's kind of like making your own backend for a smart home app, but in C++.  
You can handle users, homes, rooms, all sorts of devices (like lights, fans, locks, etc.), keep track of suppliers and inventory, and even see who uses how much energy.

---

## What does it do?

- **Accounts and Users:**  
  There are three types of accounts: Admin, User, and Guest. Each has different things they can do. Admins can manage more stuff like the workers, suppliers etc, Users are normal home owners, Guests are usually just visiting and have limited access.

- **Homes, Rooms, and Devices:**  
  A User can have one or more homes. Each home has rooms, and rooms have devices in them.  
  Devices are things like lights, fans, AC, heaters, WiFi routers, door locks, and window locks. (Currently, my company have only these :sweat_smile:)  
  Each device knows what type it is (like, a Light or a Fan) and you can make them do their own thing, for example, `adjustFeature()` is a function every device can have, but each device can adjust itself in its own way.
  
- **Energy Usage:**  
  The system also records how much energy each device uses, so you can check usage for a device, a room, or a whole home.

- **Supplier and Inventory:**  
  There’s a list of suppliers that provide device types. Suppliers keep an inventory, and inventories are stored in warehouses.  
  The system keeps track of which supplier sells which device type, how much its stock, warranty, and so on. (There is many-to-many between device types and suppliers and also some additional relational info, so I made association class between them)

- **Workers:**  
  There are workers, and each worker can be skilled with different device types. So, for example, you can know which worker to call if something breaks or needs installing. (There is many-to-many between device types and workers and also some additional relational info, so I made association class between them)
