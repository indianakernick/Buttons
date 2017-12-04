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
    Transform: {
      [if "pos" in params then "pos"]: params.pos
    },
    Text:
      if "text" in params then
        params.text
      else
        ""
  }
}
