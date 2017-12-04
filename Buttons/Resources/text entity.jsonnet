local common = import "common components.jsonnet";

function(params) {
  components: {
    TextRendering: {
      font: "Arial.ttf",
      size:
        if "size" in params then
          params.size
        else
          32
      ,
      "hori align": "center",
      "vert align": "middle"
    },
    Transform: common.transformParams(params),
    Text:
      if "text" in params then
        params.text
      else
        ""
  }
}
