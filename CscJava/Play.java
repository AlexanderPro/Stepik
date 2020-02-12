public class Play {
  public static String printTextPerRole(String[] roles, String[] textLines) {
    StringBuilder[] builders = new StringBuilder[roles.length];
      for (int i = 0; i < textLines.length; i++) {
          String line = textLines[i];
          int colonIndex = line.indexOf(':');
          String roleName = line.substring(0, colonIndex);
          int roleIndex = -1;
          for (int j = 0; j < roles.length; j++) {
              if(roles[j].equalsIgnoreCase(roleName))
              {
                  roleIndex = j;
                  break;                          
              }
          }
          if (builders[roleIndex] == null)
          {
              builders[roleIndex] = new StringBuilder();
          }
          builders[roleIndex].append((i + 1) + ")" + line.substring(colonIndex + 1) + "\n");
      }
      
      String result = "";
      for (int i = 0; i < roles.length; i++){
          if (builders[i] != null)
          {
              result += roles[i] + ":\n" + builders[i] + "\n";
          }
      }
      return result;
}  
}
