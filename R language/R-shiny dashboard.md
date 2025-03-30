```r
library(shiny)
library(shinydashboard)
library(leaflet)

# UI
header <- dashboardHeader(title = "Map Overview")

sidebar <- dashboardSidebar(
   sidebarMenu(
     menuItem("Map View", tabName = "map", icon = icon("globe"))
   )
)

body <- dashboardBody(
  tabItems(
    tabItem(
      tabName ="map",
      h1("Interactive Map"),
      leafletOutput("mymap")
    )
  )
)

ui <- dashboardPage(header,sidebar,body)


#server 

library(shiny)

 function(input, output) {
  output$mymap <- renderLeaflet({
    leaflet() %>%
      addTiles() %>%
      setView(lng = -122.4194, lat = 37.7749, zoom = 10) %>% # Center the map
      addMarkers(lng = -122.4194, lat = 37.7749, popup = "San Francisco")
  })
}
```

```
/my_app
    ├── app.R          # Main entry point for app
    ├── ui.R           # UI layout file
    ├── server.R       # Server logic file
    ├── www/           # Folder for CSS, images, JS
        ├── style.css  # Custom styles
        ├── script.js  # Custom JS
        └── logo.png   # Example image

```

**`my_data %>%`**:

- This is the **pipe operator** (`%>%`) from the `dplyr` package.
- It allows chaining operations together in a readable way.
- The data frame `my_data` is passed as the first argument to the next function in the chain.
- **`select(-state)`**:
    
    - The `select()` function is used to choose or drop columns from a data frame.
    - `-state` means "drop the `state` column."
    - After this step, the `state` column is removed from the data frame.
- **`names()`**:
    
    - The `names()` function extracts the column names of a data frame or list.
    - After dropping the `state` column, this step returns the names of the remaining columns in the data frame.

### **`global.R`: Shared Setup Code**

- **Purpose**: Contains code that runs **once** when the app is launched and is shared between the **UI** and **Server**.
- **Use Cases**:
    - Loading libraries (`library()`)
    - Loading or pre-processing data
    - Defining global variables or functions accessible to both `ui.R` and `server.R`

```R
library(shiny)
library(dplyr)

# Load data once
my_data <- read.csv("data.csv")

# Define a helper function
calculate_mean <- function(x) mean(x, na.rm = TRUE)


```

### **`server.R`: Dynamic App Logic**

- **Purpose**: Contains the **reactive server logic** that updates based on user inputs.
- **Use Cases**:
    - Handling user interactions
    - Creating reactive outputs (e.g., plots, tables)
    - Processing user input dynamically
    - 
```js
function(input, output, session) {
  output$summary <- renderText({
    paste("Mean Value:", calculate_mean(my_data$value))
  })
}


# Server
library(shiny)
library(sf)


geodata <- st_read("./test/www/map.geojson")
summary(geodata)

 function(input, output) {
  output$mymap <- renderLeaflet({
    leaflet(geodata) %>%
      addTiles() %>%
      setView(lng = 90.399452, lat = 23.777176, zoom = 6) %>% # Center the map
      addMarkers(lng = -122.4194, lat = 37.7749, popup = "San Francisco")
  })
}

library(shiny)
library(shinydashboard)
library(leaflet)
library(sf)


# UI
header <- dashboardHeader(title = "Map Overview")

sidebar <- dashboardSidebar(
   sidebarMenu(
     menuItem("Map View", tabName = "map", icon = icon("globe"))
   )
)

body <- dashboardBody(
  tabItems(
    tabItem(
      tabName ="map",
      fluidRow(
        column(width =4 ,box(title ="Total population")),
        column(width =4 ,box(title ="Top 5 population")),
        column(width =4 ,box(title ="Lowest 5 population"))
      ) ,
     
     fluidRow(
       column(width =6 ,leafletOutput("mymap")),
       column(width =6 ,h1("grapg here "))
     ),
     fluidRow(
       column(width =8 ,h1('table content here')),
       column(width =4 ,img(src='https://rstudio.github.io/leaflet/articles/images/shiny2.png',width=400))
     )
     
    )
  )
)

ui <- dashboardPage(header,sidebar,body)


```

- Use `global.R` for **shared, one-time setup code**.
- Use `server.R` for **dynamic, user-interactive app logic**.

`global.R` ensures expensive operations like loading data or defining large variables happen only once, *not every time a user interacts with the app.*

```r
library(shiny)
library(shinydashboard)
library(leaflet)
library(sf)
library(DT)
library(plotly)
library(bslib)



# UI
header <- dashboardHeader(title = "Map Overview")

sidebar <- dashboardSidebar(
   sidebarMenu(
     menuItem("Map View", tabName = "map", icon = icon("globe"))
   ),collapsed = TRUE
)

body <- dashboardBody(
  
  
  tags$head(
    tags$style(HTML("
      .dataTable {
        padding: 20px;
         margin-top: 20px; /* Add padding to the entire table */
      }
    "))
  ),
  tabItems(
    tabItem(
      tabName ="map",
      fluidRow(
        column(width =4 ,value_box(
          title = "Total Population",
          value = "16,61,36,660",
          showcase = bsicons::bs_icon("globe-central-south-asia"),
          theme = "primary",
          class = "border",
          height = 120
        ),value_box(
          title = "Population Growth Rate",
          value = "1.01%",
          showcase = bsicons::bs_icon("person-bounding-box"),
          theme = value_box_theme(bg = "#e6f2fd", fg = "#0B538E"),
          height =120
        )
        ),
        column(width =4 ,box(title = "Top 5 Populated Districts", status = "primary",  collapsible = TRUE, solidHeader = TRUE, tableOutput("low5"),width =300)),
        column(width =4 ,box(title = "less Populated Districts", status = "primary",  collapsible = TRUE, solidHeader = TRUE, tableOutput("top5"),width =300))
      ) ,
     
     fluidRow(
       column(width =8,leafletOutput("mymap",height =600 )),
       column(width =4,h1("grapg here "))
     ),
     fluidRow(
       class="custom-row",
       column(width =6 ,dataTableOutput("dataT")),
       column(width =6 ,plotlyOutput("barChart",height =600 ))
     )
     
    )
  )
)

ui <- dashboardPage(header,sidebar,body)

#server

# Server
library(shiny)
library(sf)
library(DT)
library(plotly)
library(dplyr)
library(bslib)


geodata <- st_read("./www/map.js")
# pop <- as.numeric(gsub(",", "", geodata$shapeID))
 
  
function(input, output) {
  

  geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))
  pal <- colorNumeric(palette = "YlOrRd", domain =geodata$shapeID)
  sumTotal <- sum(geodata$shapeID)
  
  sorted_data <- geodata %>%
    arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))
  
  sorted_data_asc <- geodata %>%
    arrange( geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID)))
  
  output$sum <- renderPrint(
    paste(sumTotal)
  )
  

  
   output$barChart <- renderPlotly({
     sorted_data <- geodata %>%
       arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))
    new_data <- sorted_data
     
    new_data %>%
     plot_ly() %>%
         add_bars(
           data = new_data,
           x = ~shapeName,
           y = ~shapeID)%>%
       layout(
         xaxis = list(title = "Districts"),
         yaxis = list(title = "Population")
       )
  })
   
   #Data Tables -ulta
   
    output$dataT <- renderDataTable({
    sorted_data %>%
      as.data.frame() %>%     # Convert to data frame
      select(-geometry,-shapeISO,-shapeGroup,shapeType)
  } )
  
   output$top5 <- renderTable({
     sorted_data_asc %>% 
       as.data.frame() %>%     # Convert to data frame
       select(-geometry,-shapeISO,-shapeGroup,-shapeType) %>%  # Exclude geometry column
       head(5)
   })
   
   output$low5 <- renderTable({
     sorted_data %>% 
       as.data.frame() %>%  
       select(-geometry,-shapeISO,-shapeGroup,-shapeType) %>% 
       arrange(desc(shapeID)) %>% 
       head(5)
   })
  
  output$mymap <- renderLeaflet({
    leaflet() %>%
      addProviderTiles("CartoDB.DarkMatter") %>%
      setView(lng = 90.399452, lat = 23.777176, zoom = 7) %>%  #chaining continues
      addPolygons(
        data = geodata,
        fillColor = ~pal(shapeID),
        fillOpacity = 0.8,
        color = "black",
        weight = 1,
        popup = ~paste("Population of",geodata$shapeName,":", shapeID),
        highlight = highlightOptions(
          weight = 3,
          color = "blue",
          fillColor = "lightblue",
          fillOpacity = 0.7,
          bringToFront = TRUE
        )
      ) %>% 
      addLegend(
        position = "bottomright",
        pal = pal,
        values = geodata$shapeID,
        title = "Population",
        opacity = 0.5
      ) %>%
      addMiniMap(
        width = 150,
        height = 150,
        collapsedWidth = 19,
        collapsedHeight = 19,
      )
      
  })
  
}

#newww

library(shiny)
library(shinydashboard)
library(leaflet)
library(sf)
library(DT)
library(plotly)
library(bslib)



# UI
header <- dashboardHeader(title = "Map Overview")

sidebar <- dashboardSidebar(
   sidebarMenu(
     menuItem("Map View", tabName = "map", icon = icon("globe")),
     menuItem("Table", tabName = "table", icon = icon("table")),
     menuItem("Graph", tabName = "graph", icon = icon("map")),
     menuItem("source code",icon = icon("github"),href ="https://github.com/sabberrahman?tab=repositories")
     
   ),collapsed = FALSE
)

body <- dashboardBody(
  
  
  tags$head(
    tags$style(HTML("
      .dataTable {
        padding: 20px;
         margin-top: 20px; /* Add padding to the entire table */
      }
    "))
  ),
  tabItems(
    tabItem(
      tabName ="map",
      fluidRow(
        column(width =4 ,
          selectInput("rate",label ="Rate each year",choices =names(year_data),selected = "2024",width = 100),     
          uiOutput("populationT"),
          uiOutput("rateT")
        ),
        column(width =4 ,box(title = "Top 5 Populated Districts", status = "primary",  collapsible = TRUE, solidHeader = TRUE, tableOutput("low5"),width =300)),
        column(width =4 ,box(title = "Less Populated Districts", status = "primary",  collapsible = TRUE, solidHeader = TRUE, tableOutput("top5"),width =300))
      ) ,
      
     
     fluidRow(
       column(width =8,leafletOutput("mymap",height =600 )),
       column(width =4, selectInput( 
         "location", 
         "Select options below:", 
         
         choices = choics,
         selected = "Dhaka"
       ))
     ),
     fluidRow(
       class="custom-row",
       column(width =6 ,dataTableOutput("dataT")),
       column(width =6 ,plotlyOutput("barChart",height =600 ))
     )
     
    ),
     #tab 2
    tabItem(
      tabName ="table",
      fluidRow(
        column(
          width=12,
          dataTableOutput("tableTab")
               )
      )
    ), 
    #tab 3
    tabItem(
      tabName ="graph",
      fluidRow(
        column(
          width=12,
          plotlyOutput("barchartTab",height = 700)
        )
      )
    )
 
  )
)

ui <- dashboardPage(header,sidebar,body)


#server

# Server
library(shiny)
library(sf)
library(DT)
library(plotly)
library(dplyr)
library(bslib)


geodata <- st_read("./www/map.js")
# pop <- as.numeric(gsub(",", "", geodata$shapeID))
 
  
function(input, output) {
  

  geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))
  pal <- colorNumeric(palette = "YlOrRd", domain =geodata$shapeID)
  sumTotal <- sum(geodata$shapeID)
  
  sorted_data <- geodata %>%
    arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))
  
  sorted_data_asc <- geodata %>%
    arrange( geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID)))
  
  output$sum <- renderPrint(
    paste(sumTotal)
  )
  
#------------PLOTLY---------------------
  
   output$barChart <- renderPlotly({
     sorted_data <- geodata %>%
       arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))
    new_data <- sorted_data
     
    new_data %>%
     plot_ly() %>%
         add_bars(
           data = new_data,
           x = ~shapeName,
           y = ~shapeID)%>%
       layout(
         xaxis = list(title = "Districts"),
         yaxis = list(title = "Population")
       )
  })
   
  output$barchartTab <- renderPlotly({
    sorted_data <- geodata %>%
      arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))
    new_data <- sorted_data
    
    new_data %>%
      plot_ly() %>%
      add_bars(
        data = new_data,
        x = ~shapeName,
        y = ~shapeID)%>%
      layout(
        xaxis = list(title = "Districts"),
        yaxis = list(title = "Population")
      )
  })
   # --------------Data Tables -ulta-------------------------
   
    output$dataT <- renderDataTable({
    sorted_data %>%
      as.data.frame() %>%     # Convert to data frame
      select(-geometry,-shapeISO,-shapeGroup,shapeType)%>%
        mutate(
          shapeID=scales::comma(round(shapeID))
        )%>%
        rename(
          `District`=shapeName,
          `Population`=shapeID
        )
  } )
  
  output$tableTab <- renderDataTable({
    sorted_data %>%
      as.data.frame() %>%     # Convert to data frame
      select(-geometry,-shapeISO,-shapeGroup,shapeType)%>%
      mutate(
        shapeID=scales::comma(round(shapeID))
      )%>%
      rename(
        `District`=shapeName,
        `Population`=shapeID
      )
  } )
  
   output$top5 <- renderTable({
     sorted_data_asc %>% 
       as.data.frame() %>%     # Convert to data frame
       select(-geometry,-shapeISO,-shapeGroup,-shapeType) %>%  # Exclude geometry column
       head(5)%>%
       mutate(
         shapeID=scales::comma(round(shapeID))
       )%>%
       rename(
         `District`=shapeName,
         `Population`=shapeID
       )
   })
   
   output$low5 <- renderTable({
     sorted_data %>% 
       as.data.frame() %>%  
       select(-geometry,-shapeISO,-shapeGroup,-shapeType) %>% 
       arrange(desc(shapeID)) %>% 
       head(5)%>%
       mutate(
         shapeID=scales::comma(round(shapeID))
       )%>%
       rename(
         `District`=shapeName,
         `Population`=shapeID
       )
   })
#-------------------------LEAFLET-------------------------------
  output$mymap <- renderLeaflet({
    leaflet() %>%
      addProviderTiles("CartoDB.DarkMatter") %>%
      setView(lng = 90.399452, lat = 23.777176, zoom = 7) %>%  #chaining continues
      addPolygons(
        data = geodata,
        fillColor = ~pal(shapeID),
        fillOpacity = 0.8,
        color = "black",
        weight = 1,
        popup = ~paste("Population of",geodata$shapeName,":", shapeID),
        highlight = highlightOptions(
          weight = 3,
          color = "blue",
          fillColor = "lightblue",
          fillOpacity = 0.7,
          bringToFront = TRUE
        )
      ) %>% 
      addLegend(
        position = "bottomright",
        pal = pal,
        values = geodata$shapeID,
        title = "Population",
        opacity = 0.5
      ) %>%
      addMiniMap(
        width = 150,
        height = 150,
        collapsedWidth = 19,
        collapsedHeight = 19,
      )
      
  })
#--------EVENTS-------------------------------
  
 choics <- sorted_data$shapeName
 

 
observeEvent(input$location, {
  req(input$location) # Ensure a selection is made
  
  # Find coordinates of selected location
  selected_layer <- geodata %>% 
    filter(shapeName == input$location)
  
  # Get centroid coordinates for flyTo
  selected_location <- st_centroid(selected_layer) %>%
    st_coordinates()
  
  
  # Update the map
  leafletProxy("mymap") %>%
    clearPopups() %>%
    flyTo(lng = selected_location[1], lat = selected_location[2], zoom = 10)%>%
    addPopups(
      lng = selected_location[1], 
      lat = selected_location[2],
      popup = paste(
        "<b>Location:</b>", selected_layer$shapeName, "<br>",
        "<b>Population:</b>", selected_layer$shapeID, "<br>"
        
      )
    )
})      
  
#------------dynamic ui---------------
output$populationT <- renderUI({
  value_box(
    title = "Total Population",
    value = year_data[[input$rate]]$population,  # Fetch from dataset
    showcase = bsicons::bs_icon("globe-central-south-asia"),
    theme = "primary",
    class = "border",
    height = 100
  )
})

output$rateT <- renderUI({
  value_box(
    title = "Population Growth Rate",
    value = year_data[[input$rate]]$growth_rate,  # Fetch from dataset
    showcase = bsicons::bs_icon("person-bounding-box"),
    theme = value_box_theme(bg = "white", fg = "#0B538E"),
    height = 100
  )
})


}





#global
library(shiny)
library(shinydashboard)
library(sf)
library(DT)
library(leaflet)
library(plotly)
library(dplyr)
library(bslib)
library(rsconnect)


geodata <- st_read("./www/map.js")
geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))
pal <- colorNumeric(palette = "YlOrRd", domain =geodata$shapeID)
sumTotal <- sum(geodata$shapeID)

sorted_data <- geodata %>%
  arrange( desc(geodata$shapeID <- as.numeric(gsub(",", "", geodata$shapeID))))

choics <- sorted_data$shapeName

year_data <- list(
  "2024" = list(population = "174,701,211", growth_rate = "1.01%"),
  "2023" = list(population = "172,954,319", growth_rate = "1.03%"),
  "2022" = list(population = "171,186,372", growth_rate = "1.08%"),
  "2021" = list(population = "169,356,251", growth_rate = "1.16%"),
  "2020" = list(population = "167,420,951", growth_rate = "1.15%"),
  "2019" = list(population = "165,516,222", growth_rate = "1.12%"),
  "2018" = list(population = "163,683,958", growth_rate = "1.17%"),
  "2017" = list(population = "161,793,964", growth_rate = "1.26%"),
  "2016" = list(population = "159,784,568", growth_rate = "1.24%"),
  "2015" = list(population = "157,830,000", growth_rate = "1.20%"),
  "2014" = list(population = "155,961,299", growth_rate = "1.25%"),
  "2013" = list(population = "154,030,139", growth_rate = "1.28%"),
  "2012" = list(population = "152,090,649", growth_rate = "1.25%"),
  "2011" = list(population = "150,211,005", growth_rate = "1.23%"),
  "2010" = list(population = "148,391,139", growth_rate = "1.15%"),
  "2009" = list(population = "146,706,810", growth_rate = "0.88%"),
  "2008" = list(population = "145,421,318", growth_rate = "0.89%"),
  "2007" = list(population = "144,135,934", growth_rate = "1.06%"),
  "2006" = list(population = "142,628,831", growth_rate = "1.22%"),
  "2005" = list(population = "140,912,590", growth_rate = "1.53%"),
  "2004" = list(population = "138,789,725", growth_rate = "1.68%"),
  "2003" = list(population = "136,503,206", growth_rate = "1.76%"),
  "2002" = list(population = "134,139,826", growth_rate = "1.88%"),
  "2001" = list(population = "131,670,484", growth_rate = "1.92%"),
  "2000" = list(population = "129,193,327", growth_rate = "1.92%")
)






```
