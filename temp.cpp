classDiagram
    class Patient {
        -String patientId
        -String name
        -Date dateOfBirth
        -String gender
        -String contactNumber
        -String address
        +register()
        +update()
    }
    
    class Doctor {
        -String doctorId
        -String name
        -String specialization
        -String contactNumber
        +checkAvailability()
    }
    
    class Room {
        -String roomId
        -String type
        -boolean isAvailable
        -int capacity
        +checkAvailability()
        +assignToPatient()
        +releaseRoom()
    }
    
    class Admission {
        -String admissionId
        -Patient patient
        -Doctor attendingDoctor
        -Room room
        -Date admissionDate
        -Date dischargeDate
        -String diagnosis
        -String status
        +admit()
        +discharge()
        +calculateStayDuration()
    }
    
    class Bill {
        -String billId
        -Admission admission
        -double roomCharge
        -double doctorCharge
        -double medicineCharge
        -double totalAmount
        -boolean isPaid
        +calculateTotal()
        +generateInvoice()
        +markAsPaid()
    }
    
    Patient "1" -- "0..*" Admission : has
    Doctor "1" -- "0..*" Admission : attends
    Room "1" -- "0..*" Admission : allocated to
    Admission "1" -- "1" Bill : generates