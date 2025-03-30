library(shiny)
library(openxlsx)
library(httr)
library(later)

# Define the path for the output Excel file
output_file <- "newdata.xlsx"

process_excel <- function(input_file) {
  data <- read.xlsx(input_file)
  
 
  data$Timestamp <- Sys.time()
  
  write.xlsx(data, output_file)
}

ui <- fluidPage(
  titlePanel("Real-Time Excel Processor"),
  mainPanel(
    textOutput("status")
  )
)

# Shiny Server
server <- function(input, output, session) {
  auto_process <- reactive({
    process_excel("Excel/RDT_BSE_Data_Collection-Bandarban_District_-_all_versions_-_English_en_-_2025-02-11-11-31-40.xlsx")
        invalidateLater(1000, session)
  })
  
  observe({
    auto_process()
  })
  
  shiny::addResourcePath("excel", dirname(output_file))
  output$status <- renderText({
    paste0("File is being updated. Access it at  :  http://127.0.0.1:3598/excel/", output_file)
  })
  
  
  
}

shinyApp(ui = ui, server = server)